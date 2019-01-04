/* quantity_ui.h */

#ifndef QUANTITY_UI_H
#define QUANTITY_UI_H

#include <ncurses.h>
#include "quantity.h"

WINDOW *quantityUI_createWin(Quantity * const qty);

#endif
