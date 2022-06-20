//
// Created by César on 16/05/2022.
//
#include "cards.h"

cards newCard(char* name,int rarity,effects effect[8],int costEnergy,int costMana,char* textTech,char* textDescription,bool abyssal) {

    cards new = (cards)malloc(sizeof(struct cards_));
    new->name=name;
    new->rarity=rarity;
    new->costEnegry=costEnergy;
    new->costMana=costMana;
    for (int i=0; i<8 ; i++)
    {
        if (effect[i]==NULL)
        {
            new->effect[i]=NULL;
        }
        else
        {
            new->effect[i]=effect[i];
        }
    }
    new->textTech=textTech;
    new->textDescription=textDescription;
    return new;
}

void cardActivation(cards card,monster monster)
{
    int i=0;
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
        i++;
    }while(card->effect[i]!=NULL);

}

/*
 exemple creation de strike :

effects effects[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}
effects[0]=newEffect(1,6);
newCard("Strike","basique",effects,1,0,"Inflige 6 dégâts","L’attaque de base",FALSE);

 */