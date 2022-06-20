//
// Created by César on 16/05/2022.
//
#include "items.h"


items newItem(char* name,effects effect,char* textDescription) {

    items new = malloc(sizeof(items));
    new->name=name;
    new->effect=effect;
    new->textDescription=textDescription;

    return new;
}

void itemPower(items item)
{
    if (item->effect->type==9)
        sandwich(item->effect->value);
    if (item->effect->type==10)
        strengthDef(item->effect->value);
    if (item->effect->type==11)
        dexterityDef(item->effect->value);
    if (item->effect->type==13)
        powerMax(item->effect->value);
    if (item->effect->type==12)
        HPMax(item->effect->value);
}

/*
 exemple creation de casseCroute :

effects effects=newEffect(9,6);
newItem("casseCroute",effects,"miam");

 */