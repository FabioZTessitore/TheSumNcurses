/* uiadapter.c */

#include <ncurses.h>
#include "uiadapter.h"
#include "quantity.h"
#include "quantity_ui.h"
#include "subject.h"

QuantityUI *UIAdapter_makeAndRunUI(Quantity * const qty)
{
  QuantityUI *qtyUI;

  UIAdapter_init();
  qtyUI = UIAdapter_createWin(qty);
  UIAdapter_mainloop(qty);

  return qtyUI;
}

void UIAdapter_init()
{
  initscr();
  curs_set(0);
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
}

QuantityUI *UIAdapter_createWin(Quantity * const qty)
{
  QuantityUI *qtyUI;

  int ROWS, COLS;
  getmaxyx(stdscr, ROWS, COLS);

  mvaddstr(ROWS-2, 5, "Press F2 to quit");
  mvaddstr(ROWS-7, 5, "Add a quantity (int): ");
  refresh();

  qtyUI = quantityUI_createWin(qty);
  subject_attach(qty->theSubject, qtyUI->theObserver);

  return qtyUI;
}

void UIAdapter_mainloop(Quantity * const qty)
{
  int ROWS, COLS;

  int quantityToAdd = 0;
  int c = '0';

  getmaxyx(stdscr, ROWS, COLS);

  while (c != KEY_F(2)) {
      c = '0';
      while (c != '\n' && c != KEY_F(2)) {
        if (c >= '0' && c <= '9') {
          quantityToAdd = quantityToAdd*10 + (c-'0');
        } else if (c == 'x') {
          quantityToAdd /= 10;
        }
        mvprintw(ROWS-7, 30, "%d\n", quantityToAdd);
        refresh();
        c = getch();
      }

      if (c == '\n') {
        quantity_addValue(qty, quantityToAdd);
      }
      move(ROWS-7, 30);
      quantityToAdd = 0;
      mvaddstr(ROWS-7, 30, "\n");
  }
}

void UIAdapter_finalize(QuantityUI *qtyUI)
{
  quantityUI_destroy(qtyUI);

  endwin();
}
