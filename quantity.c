/* quantity.c */

#include "quantity.h"

Quantity quantity_make(const int initialValue)
{
  Quantity newQuantity;

  newQuantity.value = initialValue;

  return newQuantity;
}

int quantity_getValue(const Quantity * const qty)
{
  return qty->value;
}

void quantity_addValue(Quantity * const qty, const int valueToAdd)
{
  qty->value += valueToAdd;
}
