#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"
#include "joueur.h"

#define nbrDistribuer 7
#define MAX_CARTES 108


int main() {
    
    srand(time(NULL));
    
    int carte_jouer = 0;
    int reste = 108;
    int i;  

    printf("%d ", reste);


    for (i = 1; i <= nbrDistribuer; i++) {
        if(carte_jouer <= MAX_CARTES ){

            int rd_type = rand() % 6;
            enum TypeCarte type;
            type = rd_type; 

            int rd_Carte = rand() % 5;
            enum Couleur couleur;
            couleur = rd_Carte;

            Carte c;
            c.type = type;
            c.couleur = couleur;

            if (type == CHIFFRE) {
                c.valeur = rand() % 10; 
            }

            printf("%d : ", i);
            afficher_carte(c);
            printf("\n");
            
            carte_jouer ++;
            reste --; 
        }
        printf("%d ", reste);
    }



    

    return 0;
}
