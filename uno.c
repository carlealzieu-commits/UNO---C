#include <stdio.h>
#include "cartes.h"

int main() {
    Carte c1 = { CHIFFRE, ROUGE, 5 };
    afficher_carte(c1);
    return 0;
}
