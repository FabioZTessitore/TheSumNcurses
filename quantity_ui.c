/* quantity_ui.c */

#include <ncurses.h>
#include "quantity.h"
#include "quantity_ui.h"
#include "observer.h"

QuantityUI quantityUI_createWin(Quantity * const qty)
{
  QuantityUI quantityUI;

  quantityUI.theWindow = newwin(7, 40, 5, 5);
  box(quantityUI.theWindow, 0 , 0);
  mvwprintw(quantityUI.theWindow, 3, 3, "Quantity: %024d", quantity_getValue(qty));
  wrefresh(quantityUI.theWindow);

  quantityUI.theObserver = observer_make((void *)&quantityUI, quantityUI_update);
  /* the Observer will have a parent pointer NULL */

  return quantityUI;
}

void quantityUI_destroy(QuantityUI *qtyUI)
{
  observer_destroy(qtyUI->theObserver);
}

void quantityUI_update(void *aQtyUI, void *data)
{
  QuantityUI *qtyUI = (QuantityUI *)aQtyUI;
  Quantity *qty = (Quantity *)data;

  mvwprintw(qtyUI->theWindow, 3, 3, "Quantity: %024d", quantity_getValue(qty));
  wrefresh(qtyUI->theWindow);
}
