#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../monsters/monsters.h"
#include "../deck/deck.h"
#include "../items/items.h"

// stats de base du joueur
#define basicCurrentPlayerHP 75
#define basicMaxPlayerHP 75
#define basicCurrentPlayerDodge 0
#define basicCurrentPlayerEnergy 0
#define basicMaxPlayerEnergy 3
#define basicCurrentPlayerMana 100
#define basicMaxPlayerMana 100
#define basicPlayerStrength 0
#define basicPlayerDexterity 0
#define basicPlayerFire 0
#define basicPlayerWeak 0
#define basicPlayerSlow 0

extern int currentPlayerHP;
extern int maxPlayerHP;
extern int currentPlayerDodge;
extern int currentPlayerEnergy;
extern int maxPlayerEnergy;
extern int currentPlayerMana;
extern int maxPlayerMana;
extern int playerStrength;
extern int playerDexterity;
extern int playerFire;
extern int playerWeak;
extern int playerSlow;
extern items tabItems[5];

void turn(int turn, monster monster, deck draw, deck discardPile, deck abysses);
void fight(deck currentDeck, monster monster);
void drawCard(deck draw, deck hand, deck discardPile);