#pragma once

#define MAX_CARTES 108

enum Couleur { ROUGE, JAUNE, BLEU, VERT, NOIR };

enum TypeCarte { CHIFFRE, PLUS2, INVERSION, PASSER, JOKER, PLUS4 };

typedef struct {
    enum TypeCarte type;
    enum Couleur couleur;
    int valeur;
} Carte;

void afficher_carte(Carte c);

