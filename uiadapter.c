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
}

void UIAdapter_finalize()
{
  endwin();
}

void UIAdapter_createWin()
{
}

void UIAdapter_mainloop()
{
}
