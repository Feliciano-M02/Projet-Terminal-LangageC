
*puissance4.h — déclarations*
c
#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#define LIGNES 6
#define COLONNES 7

void initialiserGrille();
void afficherGrille();
int jouer(int col, char symbole);
int victoire(char symbole);

#endif


*puissance4.c — implémentation*
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
    for (int j = 0; j < COLONNES; j++) printf(" %d", j);
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


*main.c — partie principale*
c
#include <stdio.h>
#include "puissance4.h"

int main() {
    int tour = 0, col;
    char symbole;
    initialiserGrille();

    while (1) {
        afficherGrille();
        symbole = (tour % 2 == 0)? 'X': 'O';
        printf("Joueur %d (%c), colonne: ", (tour % 2) + 1, symbole);
        scanf("%d", &col);

        if (col < 0 || col>= COLONNES ||!jouer(col, symbole)) {
            printf("❌ Colonne invalide. Réessaye.\n");
            continue;
}

        if (victoire(symbole)) {
            afficherGrille();
            printf("🎉 Joueur %d (%c) gagne!\n", (tour % 2) + 1, symbole);
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
