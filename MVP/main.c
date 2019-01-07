/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "quantity.h"
#include "quantity_ui.h"
#include "uiadapter.h"
#include "ioadapter.h"
#include "iotxtfile.h"
#include "subject.h"

int main()
{
  Quantity qty;
  QuantityUI *qtyUI;

  IOAdapter *ioadapter = ioadapter_make(
      iotxtfile_readData,
      iotxtfile_writeData
  );

  int *initialValueFromFile = ioadapter->readData();

  qty = quantity_make(*initialValueFromFile);
  free(initialValueFromFile);
  initialValueFromFile = NULL;

  subject_attach(qty.theSubject, ioadapter->theObserver);

  qtyUI = UIAdapter_makeAndRunUI(&qty);
  UIAdapter_finalize(qtyUI);

  ioadapter_destroy(ioadapter);
  quantity_destroy(&qty);

  return 0;
}
