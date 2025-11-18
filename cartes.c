#include <stdio.h>
#include "cartes.h"

void afficher_carte(Carte c) {

    const char *couleurs = "RJBVN";

    switch(c.type) {

        case CHIFFRE:
            printf("%d %c", c.valeur, couleurs[c.couleur]);
            break;

        case PLUS2:
            printf("+2 %c", couleurs[c.couleur]);
            break;

        case INVERSION:
            printf("RV %c", couleurs[c.couleur]);
            break;

        case PASSER:
            printf("PS %c", couleurs[c.couleur]);
            break;

        case JOKER:
            printf("JJ N");
            break;

        case PLUS4:
            printf("+4 N");
            break;

        default:
            break;
    }
}
