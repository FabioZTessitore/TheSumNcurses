/* main.c */

#include <stdio.h>
#include "quantity.h"
#include "uiadapter.h"

int main()
{
  Quantity qty;

  int initialValueFromFile = 0;

  qty = quantity_make(initialValueFromFile);
  /*
  printf("Making Quantity %d\n", initialValueFromFile);
  printf("Quantity: %d\n", quantity_getValue(&qty));

  quantity_addValue(&qty, 5);
  printf("Adding 5\n");
  printf("Quantity: %d\n", quantity_getValue(&qty));
  */
  UIAdapter_makeAndRunUI(&qty);
  UIAdapter_finalize();

  quantity_destroy(&qty);

  return 0;
}
