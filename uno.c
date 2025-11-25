#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"

#define NBR_DISTRIBUER 7
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
            rChiffre--;
            break;

        case PLUS2:
            rPlus2--;
            break;

        case INVERSION:
            rInversion--;
            break;

        case PASSER:
            rPasser--;
            break;

        case JOKER:
            rJoker--;
            break;

        case PLUS4:
            rPlus4--;
            break;

        default:
            break;
    }
}

int main() {
    srand(time(NULL));

    int carte_jouer = 0;
    int reste = MAX_CARTES;

    printf("Reste : %d\n", reste);

    for (int i = 1; i <= NBR_DISTRIBUER; i++) {

        if (reste <= 0 || carte_jouer >= MAX_CARTES) {
            printf("Plus de cartes \n");
            break;
        }

        enum TypeCarte type;
        while (1) {

            int rd_type = rand() % 6;
            type = (enum TypeCarte) rd_type;

            if (type == CHIFFRE && rChiffre > 0) break;
            if (type == PLUS2   && rPlus2 > 0)   break;
            if (type == INVERSION && rInversion > 0) break;
            if (type == PASSER  && rPasser > 0)  break;
            if (type == JOKER   && rJoker > 0)   break;
            if (type == PLUS4   && rPlus4 > 0)   break;

        }

        enum Couleur couleur;

        if (type == JOKER || type == PLUS4) {
            couleur = NOIR; 
        } else {
            int rd_couleur = rand() % 4; 
            couleur = (enum Couleur) rd_couleur;
        }

        Carte c;
        c.type = type;
        c.couleur = couleur;
        c.valeur = 0;

        if (type == CHIFFRE) {
            c.valeur = rand() % 10;
        }

        printf("%d : ", i);
        afficher_carte(c);
        printf("\n");

        gestionReste(type);
        carte_jouer++;
        reste--;
    }

    printf("Reste: %d\n", reste);

    return 0;
}
