#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"
int piocherMot(char *motPioche)
{
    FILE *dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dictionnaire.txt", "r"); // On ouvre le dictionnaire en lecture seule
    // On vérifie si on a réussi à ouvrir le dictionnaire
    if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a échoué
        // À la lecture du return, la fonction s'arrête immédiatement.
    }
    // On compte le nombre de mots dans le fichier (il suffit de compter les
    // entrées \n
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while (caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard                                          // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
    printf("\n le num choisi est %d: \n", numMotChoisi);
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    /* Le curseur du fichier est positionné au bon endroit.
    On n'a plus qu'à faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);
    printf("\n le mot pioche est %s: \n", motPioche);

    // On vire le \n à la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    printf("\n le mot pioche est apres trans %s: \n", motPioche);

    fclose(dico);
    return 1; // Tout s'est bien passé, on retourne 1
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}