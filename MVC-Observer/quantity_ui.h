/* quantity_ui.h */

#ifndef QUANTITY_UI_H
#define QUANTITY_UI_H

#include <ncurses.h>
#include "quantity.h"

#include "observer.h"

struct quantity_ui {
  WINDOW *theWindow;
  Observer *theObserver;
};

typedef struct quantity_ui QuantityUI;

/* QuantityUI is an Observer and need a parent pointer,
 * so quantityUI_createWin() must return that pointer
 */
QuantityUI *quantityUI_createWin(Quantity * const qty);

void quantityUI_destroy(QuantityUI *qtyUI);

void quantityUI_update(void *aQtyUI, void *data);

#endif
