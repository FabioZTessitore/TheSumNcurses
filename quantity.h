/* quantity.h */

#ifndef QUANTITY_H
#define QUANTITY_H

#include "subject.h"

struct quantity {
  int value;

  Subject *theSubject;
};

typedef struct quantity Quantity;

Quantity quantity_make(const int initialValue);
void quantity_destroy(Quantity *qty);
int quantity_getValue(const Quantity * const qty);
void quantity_addValue(Quantity * const qty, const int valueToAdd);

#endif
