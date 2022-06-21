#include "fight.h"

// void canPlay(cards card){

// }

// draw a card
void drawCard(deck draw, deck hand, deck discardPile){
    deck startDraw = draw;

    // refilling the draw with the discard pile
    if (draw->next == NULL)
    {
        // shuffling the discard pile
        cards *discardTab = returnDeckTab(discardPile);
        discardTab = shuffle(drawTab);
        discardPile = returnDeck(drawTab);

        while (discardPile != NULL)
        {
            addCard(draw, discardPile->card);
            discardPile = discardPile->next;
        }

        draw = startDraw;
    }

    if (hand == NULL)
    {
        hand = createDeck(draw->card);
        draw = draw->next;
    } else
    {
        deck startHand = hand;
        addCard(hand, draw->card);
        draw = draw->next;
        hand = startHand;
    }
}

void turn(int turn, monster monster, deck draw, deck discardPile, deck abysses){
    printf("Tour %d\n", turn);
    printf("hp : Peter %d %s %d\n", currentPlayerHP, monster->name, monster->hp);

    currentPlayerEnergy = maxPlayerEnergy;

    int randomValue = 0;
    switch (monster->id)
    {
        case 0:
            randomValue = rand() % 3;
            announceAbilityJawurm1(randomValue);
            break;

        case 1:
            randomValue = rand() % 2;
            announceAbilityBlouni(randomValue);
            break;

        case 2:
            randomValue = rand() % 2;
            announceAbilityKeliko(randomValue);
            break;

        case 3:
            randomValue = rand() % 3;
            announceAbilityJawurm2(randomValue);
            break;

        case 4:
            randomValue = rand() % 2;
            announceAbilityRedoni(randomValue);
            break;

        case 5:
            announceAbilityMangoustine(randomValue);
            break;

        case 6:
            randomValue = rand() % 3;
            announceAbilityEldan(randomValue);
            break;

        case 7:
            randomValue = rand() % 2;
            announceAbilityPyrox(randomValue);
            break;

        case 8:
            randomValue = rand() % 4;
            announceAbilityKeeperOfTheFeather(randomValue);
            break;
        
        default:
            break;
    }
    
    // draw 5 cards
    deck hand = NULL;
    drawCard(draw, hand, discardPile);
    drawCard(draw, hand, discardPile);
    drawCard(draw, hand, discardPile);
    drawCard(draw, hand, discardPile);
    drawCard(draw, hand, discardPile);

    // jouer cartes
    // demander au joueur la carte qu'il souhaite jouer ou s'il souhaite finir son tour
    // vérifier s'il peut jouer une carte

    int playerHPBefore = currentPlayerHP;

    switch (monster->id)
    {
        case 0:
            jawurm1Abilities(randomValue);
            break;

        case 1:
            blouniAbilities(randomValue)
            break;

        case 2:
            kelikoAbilities(randomValue)
            break;

        case 3:
            jawurm2Abilities(randomValue)
            break;

        case 4:
            redoniAbilities(randomValue)
            break;

        case 5:
            mangoustineAbilities(randomValue)
            break;

        case 6:
            eldanAbilities(randomValue)
            break;

        case 7:
            pyroxAbilities(randomValue)
            break;

        case 8:
            keeperOfTheFeatherAbilities(randomValue)
            break;
        
        default:
            break;
    }

    // if player has dodge, he takes less damage
    if (currentPlayerHP < playerHPBefore)
    {
        if (currentPlayerDodge > 0)
        {
            int diffHP = playerHPBefore-currentPlayerHP;
            if (diffHP < currentPlayerDodge)
            {
                currentPlayerHP += diffHP;
                currentPlayerDodge -= diffHP;
            }
            else
            {
                currentPlayerHP += currentPlayerDodge;
                currentPlayerDodge = 0;
            }
        }
    }

    // at the end of the turn, dodge returns to 0
    currentPlayerDodge = 0;

    // mettre les cartes non jouées dans la défausse

}

void fight(deck currentDeck, monster monster){
    displayDeck(currentDeck);
    printf("Peter affronte : %s\n", monster->name);
    printf("hp : Peter %d %s %d\n", currentPlayerHP, monster->name, monster->hp);

    for (int i = 0; i < 5; i++)
    {
        if (tabItems[i] != NULL)
        {
            items item = tabItems[i];
            if (item->active == 0)
            {
                itemPower(item);
            }
        }
    }
    currentPlayerMana = maxPlayerMana;

    deck startDeck = currentDeck;
    deck draw = createDeck(currentDeck->card);
    deck startDraw = draw;

    deck discardPile = NULL;
    deck abysses = NULL;

    // filling the draw with the current deck
    while (currentDeck->next != NULL){
        currentDeck = currentDeck->next;
        draw = draw->next;
        draw->card = currentDeck->card;
    }

    draw = startDraw;

    // shuffling the draw
    cards *drawTab = returnDeckTab(draw);
    drawTab = shuffle(drawTab);
    draw = returnDeck(drawTab);

    int turnNb = 1;
    while (monster->hp>0 && currentPlayerHP>0)
    {
        turn(turnNb, monster, draw, discardPile, abysses);
        turnNb++;
    }

    if (currentPlayerHP==0)
    {
        printf("Vous êtes mort !\n");
    } else if (monster->hp==0) {
        printf("Victoire de Peter !\n");
        // choisir une nouvelle carte parmi 3 à ajouter au deck
    }
}