/* uiadapter.c */

#include <ncurses.h>
#include "uiadapter.h"
#include "quantity.h"
#include "quantity_ui.h"

static WINDOW *quantityUI;

void UIAdapter_makeAndRunUI(Quantity * const qty)
{
  UIAdapter_init();
  UIAdapter_createWin(qty);
  UIAdapter_mainloop();
}

void UIAdapter_init()
{
  initscr();
  curs_set(0);
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
}

void UIAdapter_finalize()
{
  delwin(quantityUI);

  endwin();
}

void UIAdapter_createWin(Quantity * const qty)
{
  int ROWS, COLS;
  getmaxyx(stdscr, ROWS, COLS);

  mvaddstr(ROWS-2, 5, "Press F2 to quit");
  refresh();

  quantityUI = quantityUI_createWin(qty);
}

void UIAdapter_mainloop()
{
  int c = -1;

  while (c != KEY_F(2)) {
    c = getch();
  }
}
