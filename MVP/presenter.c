/* presenter.c */

#include <stdlib.h>
#include "presenter.h"
#include "quantity_ui.h"
#include "quantity.h"

Presenter presenter_make(QuantityUI *qtyUI, const int initialValue)
{
  Presenter p;

  p.qtyUI = qtyUI;
  p.qty = quantity_make(initialValue);

  return p;
}

void presenter_destroy(Presenter *p)
{
  quantity_destroy(&(p->qty));
}

void presenter_updateQuantity(Presenter *thePresenter, const int valueToAdd)
{
  presenter_addQuantity(thePresenter, valueToAdd);
  quantityUI_update(thePresenter->qtyUI, presenter_getQuantity(thePresenter));
}

void presenter_addQuantity(Presenter *thePresenter, const int valueToAdd)
{
  quantity_addValue(&(thePresenter->qty), valueToAdd);
}

int presenter_getQuantity(Presenter *thePresenter)
{
  return quantity_getValue(&(thePresenter->qty));
}

