#include "main.h"

void newGame(){
    srand(time(NULL));
    currentPlayerHP = basicCurrentPlayerHP;
    maxPlayerHP = basicMaxPlayerHP;
    currentPlayerDodge = basicCurrentPlayerDodge;
    currentPlayerEnergy = basicCurrentPlayerEnergy;
    maxPlayerEnergy = basicMaxPlayerEnergy;
    currentPlayerMana = basicCurrentPlayerMana;
    maxPlayerMana = basicMaxPlayerMana;
    playerStrength = basicPlayerStrength;
    playerDexterity = basicPlayerDexterity;
    playerFire = basicPlayerFire;
    playerWeak = basicPlayerWeak;
    playerSlow = basicPlayerSlow;
    tabItems = {NULL,NULL,NULL,NULL,NULL};

    // add the sandwich to the table of items
    effects tabEffects = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    tabEffects[0] = newEffect(9,6);
    items sandwich = newItem("casseCroute",tabEffects,"miam");
    tabItems[0] = sandwich;

    // creation of the starting deck
    deck currentDeck = startingDeck();

    room room = createTower();
    
    while (room->monster->name != "Keeper of the Feather")
    {
        room = goNextFloor(room);
        fight(currentDeck, room->monster);
    }

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
    scanf_s("%d", &choice);

    if (choice == 1)
    {
        newGame();
    } else if (choice == 2)
    {
        credits();
    } else if (choice == 3)
    {
        printf("\nMerci d'avoir joué !\n\n");
        exit(0);
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