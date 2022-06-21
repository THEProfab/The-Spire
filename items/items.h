//
// Created by César on 16/05/2022.
//

#ifndef THE_SPIRE_ITEMS_H
#define THE_SPIRE_ITEMS_H

#include "../effects/effects.h"

struct items_ {
    char *name;
    effects effect;
    char *textDescription;

};
typedef struct items_ *items;

items newItem(char *name, effects effect, char *textDescription);

void itemPower(items item);

#endif //THE_SPIRE_ITEMS_H