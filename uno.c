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

Carte mainJoueur[20];
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
        a = 2;
    }

    if(c.type == plateau.type && c.type != CHIFFRE && plateau.type != CHIFFRE){
        a = 3;
    }

    if(c.type == CHIFFRE && plateau.type == CHIFFRE && c.valeur == plateau.valeur){
        a = 4;
    }
    return a;
}

void afficherMain() {
    printf("\n   ");
    for(int i = 0; i < nCartesJ; i++) {
        printf(" |  %d : ", i + 1);
        afficher_carte(mainJoueur[i]);
    }
}

void piocher() {
    Carte p;

    int rd_type = rand() % 6;
    p.type = (enum TypeCarte) rd_type;

    if(p.type == JOKER || p.type == PLUS4){
        p.couleur = NOIR;
        p.valeur = 0;
    }
    else {
        p.couleur = (enum Couleur)(rand() % 4);

        if(p.type == CHIFFRE)
            p.valeur = rand() % 10;
        else
            p.valeur = 0;
    }

    mainJoueur[nCartesJ] = p;
    nCartesJ++;

    printf("\n Carte piocher:");
    afficher_carte(p);
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

        enum Couleur couleur;

        Carte c;
        c.type = type;
        c.valeur = 0;

        if (type == JOKER || type == PLUS4) {
            couleur = NOIR; 
        } else {
            int rd_couleur = rand() % 4; 
            couleur = (enum Couleur) rd_couleur;
        }
        
        c.couleur = couleur;

        if (type == CHIFFRE) {
            c.valeur = rand() % 10;
        }

        printf("%d : ", i);
        afficher_carte(c);
        printf("\n");

        gestionReste(type);
        carte_jouer++;
        reste--;

        mainJoueur[nCartesJ] = c;
        nCartesJ++;
        
        
    }

    printf("Reste: %d\n", reste);

    plateau = PremiereCarte();
    printf("Première carte:  ");
    afficher_carte(plateau);
    printf("\n");

    while(nCartesJ > 0) {

        int choixJ = 0;

        printf("\n Qu'est ce que vous voulez jouer ? ");
        scanf("%d", &choixJ);
        choixJ--;
        Carte carteChoisie = mainJoueur[choixJ];

        int verif = verifJouer(carteChoisie, plateau);
        afficherMain();

        if(verif != 0){
            printf("\n Vous avez choisie la carte suivante:");
            afficher_carte(carteChoisie);
            
            mainJoueur[choixJ] = mainJoueur[nCartesJ - 1]; 
            nCartesJ--;

            

        }else{
            printf("\n Vous ne pouvez pas jouer cette carte");
            piocher();
        }
    }      

    return 0;
}
