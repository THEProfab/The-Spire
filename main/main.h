#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../fight/fight.h"
#include "../tower/tower.h"
#include "../items/items.h"

int currentPlayerHP;
int maxPlayerHP;
int currentPlayerDodge;
int currentPlayerEnergy;
int maxPlayerEnergy;
int currentPlayerMana;
int maxPlayerMana;
int playerStrength;
int playerDexterity;
int playerFire;
int playerWeak;
int playerSlow;

items tabItems[5];

void displayMainMenu();
void newGame();
void credits();
int main();