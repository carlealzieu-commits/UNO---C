#pragma once

#define MAX_CARTES 108

#define MAX_ROUGE 19
#define MAX_VERT 19
#define MAX_JAUNE 19
#define MAX_BLEU 19
#define MAX_PLUS2 8
#define MAX_INVERSION 8
#define MAX_PASSER 8
#define MAX_JOKER 4
#define MAX_PLUS4 4


enum Couleur { ROUGE, JAUNE, BLEU, VERT, NOIR };

enum TypeCarte { CHIFFRE, PLUS2, INVERSION, PASSER, JOKER, PLUS4 };

typedef struct {
    enum TypeCarte type;
    enum Couleur couleur;
    int valeur;
} Carte;

void afficher_carte(Carte c);

