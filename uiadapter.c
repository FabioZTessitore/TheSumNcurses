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
  mvaddstr(ROWS-7, 5, "Add a quantity (int): ");
  refresh();

  quantityUI = quantityUI_createWin(qty);
}

void UIAdapter_mainloop()
{
  int ROWS, COLS;
  getmaxyx(stdscr, ROWS, COLS);

  int quantityToAdd = 0;
  int c = '0';

  while (c != KEY_F(2)) {
      c = '0';
      while (c != '\n' && c != KEY_F(2)) {
        if (c >= '0' && c <= '9') {
          quantityToAdd = quantityToAdd*10 + (c-'0');
          mvprintw(ROWS-7, 30, "%d", quantityToAdd);
          refresh();
        }
        c = getch();
      }
    move(ROWS-7, 30);

    quantityToAdd = 0;
    mvaddstr(ROWS-7, 30, "\n");
  }
}
