/* quantity.c */

#include "quantity.h"
#include "subject.h"

Quantity quantity_make(const int initialValue)
{
  Quantity newQuantity;

  newQuantity.value = initialValue;
  newQuantity.theSubject = subject_make();

  return newQuantity;
}

void quantity_destroy(Quantity *qty)
{
  subject_destroy(qty->theSubject);
}

int quantity_getValue(const Quantity * const qty)
{
  return qty->value;
}

void quantity_addValue(Quantity * const qty, const int valueToAdd)
{
  qty->value += valueToAdd;

  subject_notify(qty->theSubject, (void *)qty);
}
