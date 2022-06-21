//
// Created by César on 16/05/2022.
//
#include "cards.h"

/**
 * create a new card
 * @param name
 * @param rarity
 * @param effect
 * @param costEnergy
 * @param costMana
 * @param textTech
 * @param textDescription
 * @param abyssal
 * @return
 */
cards
newCard(char *name, int rarity, effects effect[8], int costEnergy, int costMana, char *textTech, char *textDescription,
        bool abyssal) {

    cards new = (cards) malloc(sizeof(struct cards_));
    new->name = name;
    new->rarity = rarity;
    new->costEnegry = costEnergy;
    new->costMana = costMana;
    for (int i = 0; i < 8; i++) {
        if (effect[i] == NULL) {
            new->effect[i] = NULL;
        } else {
            new->effect[i] = effect[i];
        }
    }
    new->textTech = textTech;
    new->textDescription = textDescription;
    return new;
}

/**
 * Display the parameter of a card in a terminal
 * @param card the one we want to display
 */
void displayCard(cards card) {
    printf("%s\n", card->name);
    if (card->rarity == 1) {
        printf("basique\n");
    }
    if (card->rarity == 2) {
        printf("commune\n");
    }
    if (card->rarity == 3) {
        printf("atypique\n");
    }
    if (card->rarity == 4) {
        printf("rare\n");
    }
    if (card->rarity == 5) {
        printf("special\n");
    }
    printf("text technique : %s\n", card->textTech);
    printf("text descriptif : %s\n", card->textDescription);
    if (card->abyssal == true)
        printf("abyssal\n");
}

/**
 * make cards do what they have to, like do they effect and consume mana and energy
 * @param card take the card for the activation
 * @param monster get monster for the targeting and the application of the effect
 * @return if the card can be activate true and false if it can't
 */
bool cardActivation(cards card, monster monster) {
    if (card->costEnegry > currentPlayerEnergy) // if peter have enough energy
    {
        currentPlayerEnergy -= card->costEnegry; // consume energy
    } else {
        printf("pas assez d'energy !!!!!\n");
        return false;
    }
    if (card->costMana > currentPlayerMana) // if peter have enough mana
    {
        currentPlayerMana -= card->costMana; // consume mana
    } else {
        printf("pas assez de mana !!!!!\n");
        return false;
    }
    printf("Activation de %s\n", card->name);
    printf("text technique : %s\n", card->textTech);
    printf("text descriptif : %s\n", card->textDescription);

    int i = 0; // do the effect of the card / 8 effects max
    do {
        if (card->effect[i]->type == 1)
            damage(card->effect[i]->value, monster);
        if (card->effect[i]->type == 2)
            fire(card->effect[i]->value, monster);
        if (card->effect[i]->type == 3)
            dodge(card->effect[i]->value, monster);
        if (card->effect[i]->type == 4)
            weakness(card->effect[i]->value, monster);
        if (card->effect[i]->type == 5)
            slowness(card->effect[i]->value, monster);
        if (card->effect[i]->type == 6)
            strength(card->effect[i]->value, monster);
        if (card->effect[i]->type == 7)
            dexterity(card->effect[i]->value, monster);
        if (card->effect[i]->type == 8)
            mana(card->effect[i]->value);
        i++;
    } while (card->effect[i] != NULL);
    return true;
}

/*
 exemple creation de strike :

effects effects[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
effects[0]=newEffect(1,6);
newCard("Strike","basique",effects,1,0,"Inflige 6 dégâts","L’attaque de base",FALSE);

 */