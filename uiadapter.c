/* uiadapter.c */

#include <ncurses.h>
#include "uiadapter.h"
#include "quantity.h"

void UIAdapter_makeAndRunUI(Quantity * const qty)
{
  UIAdapter_init();
  UIAdapter_createWin();
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
  endwin();
}

void UIAdapter_createWin()
{
  int ROWS, COLS;
  getmaxyx(stdscr, ROWS, COLS);

  mvaddstr(ROWS-2, 5, "Press F2 to quit");
  refresh();
}

void UIAdapter_mainloop()
{
  int c = -1;

  while (c != KEY_F(2)) {
    c = getch();
  }
}
