#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ( int argc, char** argv )
{
    // CRÉATION DES VARIABLES ET CONSTANTES UTILES
    // NB À TROUVER, NB PROPOSÉ, NB DE TENTATIVES, CONTINUER OU PASé
    int nombreMystere = 0, nombreEntre = 0;
    int nbDeCoups = 0;
    int continuerPartie = 1;
    int nbJoueurs = 1;
    int niveauDeDifficulte = 0;
    int finDuJeu;
    int MAX = 100;
    const int MIN = 1;

    // INTITIALISE LE GÉNÉRATEUR DE NOMBRES ALÉATOIRES
    srand(time(NULL));

    /* La boucle du programme. Elle se répète tant que l'utilisateur
    n'a pas trouvé le nombre mystère */
    while (continuerPartie != 0)
    {
        printf("***Bienvenue dans le jeu du Plus ou du Moins !***\n\n");
        printf("1. Mode un joueur tapez 1\n2. Mode deux joueurs tapez 2\nVotre choix : ");
        scanf("%d", &nbJoueurs);
        printf("\nChoisir la diffiulté\n");
        printf("1. Facile tapez 1\n");
        printf("2. Moeyn tapez 2\n");
        printf("3. Difficile tapez 3\n");
        printf("Votre choix : ");
        scanf("%d", &niveauDeDifficulte);

        switch(niveauDeDifficulte)
        {
            case 1:
                MAX = 100;
                break;

            case 2:
                MAX = 1000;
                break;

            case 3:
                MAX = 10000;
                break;

            default:
                printf("Veuillez choisir un niveau de difficulté 1, 2 ou 3\n");
                break;
        }

        if(niveauDeDifficulte == 1 || niveauDeDifficulte == 2 || niveauDeDifficulte == 3)
        {
            //GÉNÉRATION DU NOMBRE MYSTÈRE
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

            switch(nbJoueurs)
            {
                case 1: // MODE UN JOUEUR
                    do
                    {
                        // ON DEMANDE LE NOMBRE
                        printf("\nQuel est le nombre ? ");
                        scanf("%d", &nombreEntre);
                        // ON AJOUTE AU COMPTEUR DE TENTATIVES
                        nbDeCoups++;
                        // COMPARE LE NOMBRE ENTRÉ AVEC LE NOMBRE MYSTÈRE
                        if (nombreMystere > nombreEntre)
                        {
                            printf("C'est plus !\n\n");
                        }
                        else if (nombreMystere < nombreEntre)
                        {
                            printf("C'est moins !\n\n");
                        }
                        else if (nombreEntre == nombreMystere)
                        {
                            printf ("Bravo, vous avez trouve le nombre mystere en %d coups !\n\n", nbDeCoups);
                        }
                    } while (nombreEntre != nombreMystere); // = TANT QUE
                    break;

                case 2: //  MODE DEUX JOUEURS
                    do
                    {
                        // ON DEMANDE LE NOMBRE
                        printf("\nQuel est le nombre ? \n");
                        scanf("%d", &nombreEntre);
                        // ON AJOUTE AU COMPTEUR DE TENTATIVES
                        nbDeCoups++;
                        // COMPARE LE NOMBRE ENTRÉ AVEC LE NOMBRE MYSTÈRE
                        if (nombreMystere > nombreEntre)
                        {
                            printf("C'est plus !\n\n");
                        }
                        else if (nombreMystere < nombreEntre)
                        {
                            printf("C'est moins !\n\n");
                        }
                        else if (nombreEntre == nombreMystere)
                        {
                            printf ("Bravo, vous avez trouve le nombre mystere en %d coups !\n\n", nbDeCoups);
                        }
                    } while (nombreEntre != nombreMystere); // = TANT QUE
                    break;
                default:
                    printf("Nombre de joueurs erroné. Veuillez taper 1 ou 2\n");
                    break;
            }
        }

        printf("Voulez vous faire une nouvelle partie ?\n");
        printf("1. Oui, tapez 1\n2. Non, tapez 0\nVotre choix : ");
        scanf("%d", &continuerPartie);
        printf("\n\n");
    }// while (continuerPartie != 0);
return 0;
}  // int main();



