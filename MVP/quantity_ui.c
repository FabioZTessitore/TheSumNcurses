/* quantity_ui.c */

#include <stdlib.h>
#include <ncurses.h>
#include "quantity_ui.h"

QuantityUI *quantityUI_createWin(const int initialValue)
{
  QuantityUI *quantityUI = (QuantityUI *)malloc(sizeof(quantityUI));

  quantityUI->theWindow = newwin(7, 40, 5, 5);
  box(quantityUI->theWindow, 0 , 0);

  quantityUI_update(quantityUI, initialValue);

  return quantityUI;
}

void quantityUI_destroy(QuantityUI *qtyUI)
{
  if (qtyUI != NULL) {
    delwin(qtyUI->theWindow);
    free(qtyUI);
    qtyUI = NULL;
  }
}

void quantityUI_update(QuantityUI *theQtyUI, const int value)
{
  mvwprintw(theQtyUI->theWindow, 3, 3, "Quantity: %024d", value);
  wrefresh(theQtyUI->theWindow);
}
