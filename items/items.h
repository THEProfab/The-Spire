//
// Created by César on 16/05/2022.
//

#ifndef THE_SPIRE_ITEMS_H
#define THE_SPIRE_ITEMS_H
#include "effects.c"

struct items_ ;
typedef struct items_ * items;

#endif //THE_SPIRE_ITEMS_H

items newItem(char* name,effects effect,char* textDescription);
void itemPower(items item);
