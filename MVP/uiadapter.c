/* uiadapter.c */

#include <ncurses.h>
#include "uiadapter.h"
#include "quantity_ui.h"
#include "presenter.h"
#include "subject.h"
#include "ioadapter.h"

QuantityUI *UIAdapter_makeAndRunUI(const int initialValue, IOAdapter *ioadapter)
{
  QuantityUI *qtyUI;
  Presenter p;

  UIAdapter_init();
  qtyUI = UIAdapter_createWin(initialValue);
  p = presenter_make(qtyUI, initialValue);
  subject_attach(p.qty.theSubject, ioadapter->theObserver);
  UIAdapter_mainloop(&p);

  presenter_destroy(&p);
  UIAdapter_finalize(qtyUI);

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

QuantityUI *UIAdapter_createWin(const int initialValue)
{
  QuantityUI *qtyUI;

  int ROWS, COLS;
  getmaxyx(stdscr, ROWS, COLS);

  mvaddstr(ROWS-2, 5, "Press F2 to quit");
  mvaddstr(ROWS-7, 5, "Add a quantity (int): ");
  refresh();

  qtyUI = quantityUI_createWin(initialValue);

  return qtyUI;
}

void UIAdapter_mainloop(Presenter *p)
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
        presenter_updateQuantity(p, quantityToAdd);
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
