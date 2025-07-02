
#include <stdio.h>
#include "puissance4.h"

int main() {
    int tour = 0, col;
    char symbole;

    initialiserGrille();

    while (1) {
        afficherGrille();
        symbole = (tour % 2 == 0)? 'X': 'O';
        printf("Joueur %d (%c), entrez la colonne: ", (tour % 2) + 1, symbole);
        scanf("%d", &col);

        if (col < 0 || col>= COLONNES ||!jouer(col, symbole)) {
            printf("❌ Colonne invalide ou pleine. Réessayez.\n");
            continue;
}

        if (victoire(symbole)) {
            afficherGrille();
            printf("🎉 Le joueur %d (%c) a gagné!\n", (tour % 2) + 1, symbole);
            break;
}

        if (++tour>= LIGNES * COLONNES) {
            afficherGrille();
            printf("⚖ Match nul!\n");
            break;
}
}

    return 0;
}
