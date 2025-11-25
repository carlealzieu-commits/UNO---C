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

Carte mainJoueur[108];
int nCartesJ = 0; 

Carte plateau;

int rChiffre = MAX_CHIFFRE;
int rPlus2 = MAX_PLUS2;
int rInversion = MAX_INVERSION;
int rPasser = MAX_PASSER;
int rJoker = MAX_JOKER;
int rPlus4 = MAX_PLUS4;

Carte PremiereCarte() {
    Carte c;

    c.type = CHIFFRE;
    c.couleur = (enum Couleur)(rand() % 4);
    c.valeur = rand() % 10;

    return c;
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


int verifJouer(Carte c, Carte plateau){
    int a = 0;
    if(c.type == JOKER || plateau.type == PLUS4){
        a = 1;
    }

    if(c.couleur == plateau.couleur){
        a = 1;
    }

    if(c.type == plateau.type && c.type != CHIFFRE && plateau.type != CHIFFRE){
        a = 1;
    }

    if(c.type == CHIFFRE && plateau.type == CHIFFRE && c.valeur == plateau.valeur){
        a = 1;
    }

    return a;
}

void afficherMain() {
    printf("\n  ");
    for(int i = 0; i < nCartesJ; i++) {
        printf(" | %d : ", i + 1);
        afficher_carte(mainJoueur[i]);
    }
    printf(" | \n");
}

Carte generationCarte() {
    Carte c;
        enum TypeCarte type;

        while (1) {

            int rd_type = rand() % 6;
            type = (enum TypeCarte) rd_type;

            if (type == CHIFFRE && rChiffre > 0) break;
            if (type == PLUS2 && rPlus2 > 0)   break;
            if (type == INVERSION && rInversion > 0) break;
            if (type == PASSER && rPasser > 0)  break;
            if (type == JOKER && rJoker > 0)   break;
            if (type == PLUS4 && rPlus4 > 0)   break;

        }

        c.type = type;
        c.valeur = 0;

        if (type == JOKER || type == PLUS4) {
            c.couleur = NOIR; 
        } else {
            int rd_couleur = rand() % 4; 
            c.couleur = (enum Couleur) rd_couleur;
        }
        

        if (type == CHIFFRE) {
            c.valeur = rand() % 10;
        }

    return c;
}

int main() {
    
    srand(time(NULL));

    int carte_jouer = 0;
    int reste = MAX_CARTES;

    for (int i = 1; i <= NBR_DISTRIBUER; i++) {

        if (reste <= 0 || carte_jouer >= MAX_CARTES) {
            printf("Plus de cartes \n");
            break;
        }
        
        Carte c = generationCarte();
    
        mainJoueur[nCartesJ] = c;
        nCartesJ++;
        carte_jouer++;
        reste--;
    }

    printf("\n");
    afficherMain();
    printf("\n");
    printf("Reste: %d\n", reste);

    printf("\n");
    plateau = PremiereCarte();
    printf("Première carte:  ");
    afficher_carte(plateau);
    printf("\n");

    while(nCartesJ > 0) {

        int choixJ = 0;

        printf("\n");
        printf("\n");
        printf("Qu'est ce que vous voulez jouer ? ");
        scanf("%d", &choixJ);
        choixJ--;
        Carte carteChoisie = mainJoueur[choixJ];

        int verif = verifJouer(carteChoisie, plateau);

        if(verif != 0){
            printf("\n Vous avez choisie la carte suivante:");
            afficher_carte(carteChoisie);
            
            mainJoueur[choixJ] = mainJoueur[nCartesJ - 1]; 
            nCartesJ--;

            afficherMain();

            

        }else{
            printf("\n Pas possible de jouer cette carte, vous piocher.");
            
            afficherMain();

        }
    }      

    return 0;
}
