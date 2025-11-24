#include <stdio.h>
#include "joueur.h"


void ajouter_carte(Joueur *j, Carte c) {
    j->main[j->nbCartes] = c; 
    j->nbCartes++;             
}


void afficher_main(Joueur j) {
    for (int i = 0; i < j.nbCartes; i++) {
            afficher_carte(j.main[i]);
            if (i < j.nbCartes - 1) {
                printf(" | ");
            }
        }
}