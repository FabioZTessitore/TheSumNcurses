/* main.c */

#include <stdio.h>
#include "quantity.h"
#include "quantity_ui.h"
#include "uiadapter.h"

int main()
{
  Quantity qty;
  QuantityUI *qtyUI;

  int initialValueFromFile = 0;

  qty = quantity_make(initialValueFromFile);

  qtyUI = UIAdapter_makeAndRunUI(&qty);
  UIAdapter_finalize(qtyUI);

  quantity_destroy(&qty);

  return 0;
}
