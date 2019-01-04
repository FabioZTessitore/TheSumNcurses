/* uiadapter.c */

#include <ncurses.h>
#include "uiadapter.h"
#include "quantity.h"
#include "quantity_ui.h"
#include "subject.h"

static QuantityUI quantityUI;

void UIAdapter_makeAndRunUI(Quantity * const qty)
{
  UIAdapter_init();
  UIAdapter_createWin(qty);

  if (qty->theSubject == NULL) {
    mvprintw(0, 0, "UIADAPTER: MAKE AND RUN UI: Subject is NULL\n");
  }

  UIAdapter_mainloop(qty);
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
  quantityUI_destroy(&quantityUI);
  delwin(quantityUI.theWindow);

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
  (quantityUI.theObserver)->parent = &quantityUI;
  subject_attach(qty->theSubject, quantityUI.theObserver);

  if (quantityUI.theObserver == NULL){
    mvprintw(20, 0, "createWin(): Observer NULL");
  } else if ((quantityUI.theObserver)->parent == NULL){
    mvprintw(20, 0, "createWin(): parent NULL");
  } else if ((quantityUI.theObserver)->parent != &quantityUI) {
    mvprintw(20, 0, "createWin(): parent errato");
  }


}

void UIAdapter_mainloop(Quantity * const qty)
{
  if (qty->theSubject == NULL) {
    mvprintw(0, 0, "UIADAPTER: MAINLOOP: Subject is NULL\n");
  }

  int ROWS, COLS;
  getmaxyx(stdscr, ROWS, COLS);

  int quantityToAdd = 0;
  int c = '0';

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
