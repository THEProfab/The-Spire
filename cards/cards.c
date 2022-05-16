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

cards newCard(char* name,int rarity,int costEnergie,int costMana,effects effect[8],char* textTech,char* textDescription,bool abyssal) {

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
