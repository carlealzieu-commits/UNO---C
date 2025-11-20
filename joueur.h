#pragma once         
#include "cartes.h"

typedef struct {
    Carte main[30];
    int nbCartes;
} Joueur;

void ajouter_carte(Joueur *j, Carte c);

void afficher_main(Joueur j);

