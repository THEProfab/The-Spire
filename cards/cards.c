//
// Created by César on 16/05/2022.
//
#include <bool.h>
#include "cards.h"

struct cards_ {

    char* name;
    int rarity; //can be : 1=basique, 2=commune, 3=atypique, 4=rare, 5=special
    int costEnegrie;// max = 3
    int costMana;// max = 20
    effects effect[8];// their can have 8 effects max
    char* textTech;
    char* textDescription;
    bool abyssal;// is abyssal or not - 1 or 0
};

cards newCard(char* name,int rarity,effects effect[8],int costEnergie,int costMana,char* textTech,char* textDescription,bool abyssal) {

    cards new = malloc(sizeof(cards_));
    new->name=name;
    new->rarity=rarity;
    new->costEnegrie=costEnergie;
    new->costMana=costMana;
    for (int i=0; i<8 ; i++)
    {
        if (effect[i]=!NULL)
        {
            new->effect=NULL;
        }
        else
        {
            new->effect=effect;
        }
    }
    new->textTech=textTech;
    new->textDescription=textDescription;
    return new;
}

void cardActivation(cards card,monster monster)
{
    do{
        if (card->effect[i]->type==1)
            damage(card->effect[i]->value,monster);
        if (card->effect[i]->type==2)
            fire(card->effect[i]->value,monster);
        if (card->effect[i]->type==3)
            dodge(card->effect[i]->value,monster);
        if (card->effect[i]->type==4)
            weakness(card->effect[i]->value,monster);
        if (card->effect[i]->type==5)
            slowness(card->effect[i]->value,monster);
        if (card->effect[i]->type==6)
            strength(card->effect[i]->value,monster);
        if (card->effect[i]->type==7)
            dexterity(card->effect[i]->value,monster);
    }while(effect[i]!=NULL);
}

/*
 exemple creation de strike :

effects effects[0]=newEffect(1,6);
newCard("Strike","basique",effects,1,0,"Inflige 6 dégâts","L’attaque de base",FALSE);

 */