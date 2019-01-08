/* quantity_ui.h */

#ifndef QUANTITY_UI_H
#define QUANTITY_UI_H

#include <ncurses.h>

struct quantity_ui {
  WINDOW *theWindow;
};

typedef struct quantity_ui QuantityUI;

QuantityUI *quantityUI_createWin(const int initialValue);
void quantityUI_destroy(QuantityUI *qtyUI);

void quantityUI_update(QuantityUI *theQtyUI, const int value);

#endif
