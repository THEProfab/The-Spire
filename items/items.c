//
// Created by César on 16/05/2022.
//
#include "items.h"

struct items_ {
    int type; // 1=hp, 2=strength, 3=dex, 4=Hp max, 5=morepower
    int value; // power
};

items newItem(char* name,effects effect,char* textDescription) {

    items new = malloc(sizeof(items_));
    new->type=type;
    new->value=value;

    return new;
}

void itemPower(items item)
{
    if (item->effect->type==9)
        casseCrout(item->effect->value);
    if (item->effect->type==10)
        strength(item->effect->value);
    if (card->effect->type==11)
        dexterity(item->effect->value);
    if (card->effect->type==12)
        powerMax(item->effect->value);
}