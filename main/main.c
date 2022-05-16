#include "main.h"

void newGame(){
    printf("\nWIP\n\n");
    displayMainMenu();
}

void credits(){
    printf("\nCrédits :\n");
    printf("Projet de C basé sur le jeu 'Slay the Spire'.\n");
    printf("Développé par Étienne EL GUEDER, Loïc CLEDELIN, César DUVAL et Marc BAYART.\n\n");
    displayMainMenu();
}

void displayMainMenu(){
    int choice = 0;
    printf("1. Nouvelle partie\n");
    printf("2. Crédits\n");
    printf("3. Quitter\n");
    printf("Que souhaitez-vous faire ? (entrez 1, 2 ou 3) ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        newGame();
    } else if (choice == 2)
    {
        credits();
    } else if (choice == 3)
    {
        printf("\nMerci d'avoir joué !\n\n");
        exit;
    } else
    {
        printf("\nVous avez saisi un mauvais chiffre !\n\n");
        displayMainMenu();
    }
}

int main(){
    printf("Bienvenue dans C the Spire !\n\n");
    displayMainMenu();

    return 1;
}