/* quantity.c */

#include "quantity.h"
#include "subject.h"

#include <ncurses.h>

Quantity quantity_make(const int initialValue)
{
  Quantity newQuantity;

  newQuantity.value = initialValue;

  newQuantity.theSubject = subject_make();

  if (newQuantity.theSubject == NULL) {
    mvprintw(0, 0, "MAKE: Subject is NULL\n");
  }

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

  if (qty->theSubject == NULL) {
    mvprintw(10, 0, "Subject is NULL\n");
    printf("Subject is NULL\n");
  } else {
    subject_notify(qty->theSubject, (void *)qty);
  }
}
