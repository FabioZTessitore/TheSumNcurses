/* quantity_ui.c */

#include <ncurses.h>
#include "quantity.h"
#include "quantity_ui.h"

WINDOW *quantityUI_createWin(Quantity * const qty)
{
  WINDOW *quantity_ui_win;

  quantity_ui_win = newwin(7, 40, 5, 5);
  box(quantity_ui_win, 0 , 0);
  mvwprintw(quantity_ui_win, 3, 3, "Quantity: %024d", quantity_getValue(qty));
  wrefresh(quantity_ui_win);

  return quantity_ui_win;
}
