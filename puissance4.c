
c
#include <stdio.h>
#include "puissance4.h"

char grille[LIGNES][COLONNES];

void initialiserGrille() {
    for (int i = 0; i < LIGNES; i++)
        for (int j = 0; j < COLONNES; j++)
            grille[i][j] = '.';
}

void afficherGrille() {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++)
            printf(" %c", grille[i][j]);
        printf("\n");
}
    for (int j = 0; j < COLONNES; j++)
        printf(" %d", j);
    printf("\n");
}

int jouer(int col, char symbole) {
    for (int i = LIGNES - 1; i>= 0; i--) {
        if (grille[i][col] == '.') {
            grille[i][col] = symbole;
            return 1;
}
}
    return 0;
}

int victoire(char symbole) {
    for (int i = 0; i < LIGNES; i++)
        for (int j = 0; j <= COLONNES - 4; j++)
            if (grille[i][j] == symbole && grille[i][j+1] == symbole &&
                grille[i][j+2] == symbole && grille[i][j+3] == symbole)
                return 1;
    for (int j = 0; j < COLONNES; j++)
        for (int i = 0; i <= LIGNES - 4; i++)
            if (grille[i][j] == symbole && grille[i+1][j] == symbole &&
                grille[i+2][j] == symbole && grille[i+3][j] == symbole)
                return 1;
    for (int i = 0; i <= LIGNES - 4; i++)
        for (int j = 0; j <= COLONNES - 4; j++)
            if (grille[i][j] == symbole && grille[i+1][j+1] == symbole &&
                grille[i+2][j+2] == symbole && grille[i+3][j+3] == symbole)
                return 1;
    for (int i = 3; i < LIGNES; i++)
        for (int j = 0; j <= COLONNES - 4; j++)
            if (grille[i][j] == symbole && grille[i-1][j+1] == symbole &&
                grille[i-2][j+2] == symbole && grille[i-3][j+3] == symbole)
                return 1;
    return 0;
}
