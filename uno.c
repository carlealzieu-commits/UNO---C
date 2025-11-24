#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"
#include "joueur.h"

#define nbrDistribuer 7
#define MAX_CARTES 108
#define MAX_CHIFFRE 76
#define MAX_PLUS2 8
#define MAX_INVERSION 8
#define MAX_PASSER 8
#define MAX_JOKER 4
#define MAX_PLUS4 4


int rChiffre = MAX_CHIFFRE;
int rPlus2 = MAX_PLUS2;
int rInversion = MAX_INVERSION;
int rPasser = MAX_PASSER;
int rJoker = MAX_JOKER;
int rPlus4 = MAX_PLUS4;

void afficherReste() {
    printf("CHIFFRE   : %d\n", rChiffre);
    printf("PLUS2     : %d\n", rPlus2);
    printf("INVERSION : %d\n", rInversion);
    printf("PASSER    : %d\n", rPasser);
    printf("JOKER     : %d\n", rJoker);
    printf("PLUS4     : %d\n", rPlus4);
}

void gestionReste (int type) {
        switch (type) {

        case CHIFFRE:
            rChiffre --;
        break;

        case PLUS2:
            rPlus2 --;
        break;

        case INVERSION:
            rInversion --;
        break;

        case PASSER:
            rPasser --;
        break;

        case JOKER:
            rJoker --;
        break;

        case PLUS4:
            rPlus4 --;
        break;

        default:
    }
        
}

int main() {
    
    srand(time(NULL));
    
    int carte_jouer = 0;
    int reste = 108;

    printf("%d ", reste);

    int i;
    for (i = 1; i <= nbrDistribuer; i++) {
        if((carte_jouer < MAX_CARTES) && (rChiffre > 0) && (rPlus2 > 0) && (rInversion > 0) && (rPasser > 0)&& (rPlus4 > 0)){

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

            gestionReste(type);
            
            carte_jouer ++;
            reste --; 
        }
        printf("%d ", reste);
    }



    

    return 0;
}
