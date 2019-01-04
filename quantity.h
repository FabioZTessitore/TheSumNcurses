/* quantity.h */

#ifndef QUANTITY_H
#define QUANTITY_H

struct quantity {
  int value;
};

typedef struct quantity Quantity;

Quantity quantity_make(const int initialValue);
int quantity_getValue(const Quantity * const qty);
void quantity_addValue(Quantity * const qty, const int valueToAdd);

#endif
