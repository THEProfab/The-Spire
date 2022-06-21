#include "fight.h"

void playCard(deck hand, int* handSize, monster monster, deck discardPile, deck abysses){
    deck startHand = hand;
    printf("Votre main est actuellement constituée de :\n");
    
    while(hand != NULL){
        displayCard(hand->card);
        hand = hand->next;
    }

    hand = startHand;
    deck prevHand = NULL;

    int choice = 0;
    printf("Choisissez le numéro de la carte à jouer (de 1 à %d) : ", *handSize);
    scanf_s("%d", &choice);

    while (choice>*handSize || choice<1)
    {
        printf("Merci de choisir un numéro valide (de 1 à %d) : ", *handSize);
        scanf_s("%d", &choice);
    }
    
    for (int i = 1; i < choice; i++)
    {
        prevHand = hand;
        hand = hand->next;
    }

    bool played = cardActivation(hand->card, monster);

    // removing the played card from the hand
    if (played)
    {
        if (choice==1)
        {
            startHand = hand->next;
        }
        else if (choice==(*handSize))
        {
            prevHand->next = NULL;
        }
        else
        {
            prevHand->next = hand->next;
        }

        // putting the played card into the abysses or the discard pile
        if (hand->card->abyssal)
        {
            if (abysses == NULL)
            {
                abysses = createDeck(hand->card);
            } else 
            {
                addCard(abysses, hand->card);
            }  
        } else
        {
            if (discardPile == NULL)
            {
                discardPile = createDeck(hand->card);
            } else
            {
                addCard(discardPile, hand->card);
            }
        }

        (*handSize)--;
    }

    hand = startHand;
}

// draw a card
void drawCard(deck draw, deck hand, deck discardPile){
    deck startDraw = draw;

    // refilling the draw with the discard pile
    if (draw->next == NULL)
    {
        // shuffling the discard pile
        cards *discardTab = returnDeckTab(discardPile);
        discardTab = shuffle(discardTab);
        discardPile = returnDeck(discardTab);

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

// what's happening during a turn of a fight
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

    deck startHand = hand;
    
    printf("Votre main est actuellement constituée de :\n");
    
    while(hand != NULL){
        displayCard(hand->card);
        hand = hand->next;
    }

    int monsterHPBefore = monster->hp;

    hand = startHand;
    int handSize = 5;

    int choice = 0;
    printf("1. Jouer une carte\n");
    printf("2. Fin du tour\n");
    scanf_s("%d", &choice);
    while (choice != 2)
    {
        playCard(hand, &handSize, monster, discardPile, abysses);
        printf("1. Jouer une carte\n");
        printf("2. Fin du tour\n");
        scanf_s("%d", &choice);
    }

    // if the monster has dodge, it takes less damage
    if (monster->hp < monsterHPBefore)
    {
        if (monster->dodge > 0)
        {
            int diffHP = monsterHPBefore-monster->hp;
            if (diffHP < monster->dodge)
            {
                monster->hp += diffHP;
                monster->dodge -= diffHP;
            }
            else
            {
                monster->hp += monster->dodge;
                monster->dodge = 0;
            }
        }
    }

    monster->dodge = 0;

    // if the monster has no more hp, the fight is finished
    if (monster->hp == 0)
    {
        return;
    }

    int playerHPBefore = currentPlayerHP;

    switch (monster->id)
    {
        case 0:
            jawurm1Abilities(randomValue);
            break;

        case 1:
            blouniAbilities(randomValue);
            break;

        case 2:
            kelikoAbilities(randomValue);
            break;

        case 3:
            jawurm2Abilities(randomValue);
            break;

        case 4:
            redoniAbilities(randomValue);
            break;

        case 5:
            mangoustineAbilities(randomValue);
            break;

        case 6:
            eldanAbilities(randomValue);
            break;

        case 7:
            pyroxAbilities(randomValue);
            break;

        case 8:
            keeperOfTheFeatherAbilities(randomValue);
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

    // putting the unplayed cards into the discard pile
    while (hand != NULL)
    {
        if (discardPile == NULL)
        {
            discardPile = createDeck(hand->card);
        } else
        {
            addCard(discardPile, hand->card);
        }
        hand = hand->next;
    }
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

        // chosing 3 cards randomly
        deck toChose = NULL;
        deck startChose = toChose;
        for (int i = 0; i < 2; i++)
        {
            int randomValue = rand() % 12;
            cards card;

            switch (randomValue)
            {
            case 0:
                card = createStrike();
                break;
            case 1:
                card = createEsquive();
                break;
            case 2:
                card = createDoubleStrike();
                break;
            case 3:
                card = createBouleDeFeu();
                break;
            case 4:
                card = createCoupAffaiblissant();
                break;
            case 5:
                card = createAcceleration();
                break;
            case 6:
                card = createSurmenage();
                break;
            case 7:
                card = createPostureDefensive();
                break;
            case 8:
                card = createConcentration();
                break;
            case 9:
                card = createIncendie();
                break;
            case 10:
                card = createPulveriser();
                break;
            case 11:
                card = createSpectreComplet();
                break;
            
            default:
                // easter egg
                card = createMartinsFury();
                break;
            }

            if (toChose == NULL)
            {
                toChose = createDeck(card);
                startChose = toChose;
            } else
            {
                addCard(toChose, card);
            }  
        }
        toChose = startChose;

        printf("Voici 3 cartes :\n");
        while(toChose != NULL){
            displayCard(toChose->card);
            toChose = toChose->next;
        }
        toChose = startChose;

        printf("Choisissez-en une à ajouter à votre deck (de 1 à 3) :\n");
        int choice = 0;
        scanf_s("%d", &choice);
        while (choice<1 || choice>3)
        {
            printf("Veuillez entrer un numéro valide (entre 1 et 3) !");
            scanf_s("%d", &choice);
        }

        for (int i = 1; i < choice; i++)
        {
            toChose = toChose->next;
        }
        
        addCard(currentDeck, toChose->card);
    }
}