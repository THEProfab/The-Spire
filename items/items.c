//
// Created by César on 16/05/2022.
//
#include "items.h"

/**
 * create a new item
 * @param name
 * @param effect
 * @param textDescription
 * @return
 */
items newItem(char *name, effects effect, char *textDescription) {

    items new = malloc(sizeof(items));
    new->name=name;
    new->effect=effect;
    new->textDescription=textDescription;
    new->active = 0;

    return new;
}

/**
 * do the effect of an item
 * @param item
 */
void itemPower(items item)
{
    if (item->effect->type==9)
        sandwich();
    if (item->effect->type==10){
        strengthDef(item->effect->value);
        item->active = 1;
    }
    if (item->effect->type==11){
        dexterityDef(item->effect->value);
        item->active = 1;
    }
    if (item->effect->type==12){
        HPMax(item->effect->value);
        item->active = 1;
    }
    if (item->effect->type==13){
        powerMax(item->effect->value);
        item->active = 1;
    }
}

/*
 exemple creation de casseCroute :

effects effects=newEffect(9,6);
newItem("casseCroute",effects,"miam");

 */