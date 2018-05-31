#include "list.h"

Point GetPoint();

int main (void)
{
    char choix;
    Point newPoint;

    Liste *liste;
    //Element *courant;
    if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
        return -1;
    //courant = NULL;
    choix = 'o';
    initialisation (liste);

    int pos, k;

    while (choix != 7)
    {
        choix = menu (liste, &k);
        switch (choix)
        {
            case 1:
                printf ("Entrez un element : ");
                newPoint = GetPoint();
                if (liste->taille == 0)
                    insListeVide(liste, newPoint);
                else
                insDebutListe (liste, newPoint);
                printf ("%d elements : deb= x = %d  y = %d  z = %d, fin= x = %d  y = %d  z = %d\n", liste->taille, liste->debut->donnee->x, liste->debut->donnee->y, liste->debut->donnee->z,
                        liste->fin->donnee->x, liste->fin->donnee->y, liste->fin->donnee->z);
                affiche(liste);
                break;
            case 2:
                printf ("Entrez un element : ");
                newPoint = GetPoint();
                insFinListe (liste, liste->fin, newPoint);
                printf ("%d elements : deb= x = %d  y = %d  z = %d, fin= x = %d  y = %d  z = %d\n", liste->taille, liste->debut->donnee->x, liste->debut->donnee->y, liste->debut->donnee->z,
                        liste->fin->donnee->x, liste->fin->donnee->y, liste->fin->donnee->z);
                affiche(liste);
                break;
            case 3:
                printf ("Entrez un element : ");
                newPoint = GetPoint();
                do
                {
                    printf ("Entrez la position : ");
                    scanf ("%d", &pos);
                }
                while (pos < 1 || pos > liste->taille);
                getchar ();
                if (liste->taille == 1 || pos == liste->taille)
                {
                    k = 1;
                    printf("-----------------------------------------------\n");
                    printf("Insertion echouée.Utilisez le menu {1|2} \n");
                    printf("-----------------------------------------------\n");
                    break;
                }
                insListe (liste, newPoint, pos);
                printf ("%d elements : deb= x = %d  y = %d  z = %d, fin= x = %d  y = %d  z = %d\n", liste->taille, liste->debut->donnee->x, liste->debut->donnee->y, liste->debut->donnee->z,
                        liste->fin->donnee->x, liste->fin->donnee->y, liste->fin->donnee->z);
                affiche (liste);
            break;
            case 4:
                suppDebut (liste);
                if (liste->taille != 0)
                printf ("%d elements : deb= x = %d  y = %d  z = %d, fin= x = %d  y = %d  z = %d\n", liste->taille, liste->debut->donnee->x, liste->debut->donnee->y, liste->debut->donnee->z,
                        liste->fin->donnee->x, liste->fin->donnee->y, liste->fin->donnee->z);
                else
                    printf ("liste vide\n");
                affiche (liste);
                break;
                case 5:
                do
                {
                    printf ("Entrez la position : ");
                    scanf ("%d", &pos);
                }
                while (pos < 1 || pos > liste->taille);
                    getchar ();
                    suppDansListe (liste, pos);
                if (liste->taille != 0)
                printf ("%d elements : deb= x = %d  y = %d  z = %d, fin= x = %d  y = %d  z = %d\n", liste->taille, liste->debut->donnee->x, liste->debut->donnee->y, liste->debut->donnee->z,
                        liste->fin->donnee->x, liste->fin->donnee->y, liste->fin->donnee->z);
                else
                    printf ("liste vide\n");
                    affiche (liste);
                break;
            case 6:
                detruire (liste);
                printf ("la liste a ete detruite : %d elements\n", liste->taille);
            break;
        }
    }
    return 0;
}

Point GetPoint()
{
    Point locPoint = {0, 0, 0};
    printf("\nx :\n");
    scanf("%d", &locPoint.x);
    printf("y :\n");
    scanf("%d", &locPoint.y);
    printf("z :\n");
    scanf("%d", &locPoint.z);
    return locPoint;
}
