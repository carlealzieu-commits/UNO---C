#include <stdio.h>
#include "cartes.h"
#include "joueur.h"

int main() {
    Joueur j = { .nbCartes = 0 };

    Carte c1 = { CHIFFRE, ROUGE, 1 };
    Carte c2 = { CHIFFRE, ROUGE, 2 };
    Carte c3 = { CHIFFRE, ROUGE, 3 };

    ajouter_carte(&j, c1);
    ajouter_carte(&j, c2);
    ajouter_carte(&j, c3);

    afficher_main(j);
    return 0;
}
