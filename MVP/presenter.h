/* presenter.h */

#ifndef PRESENTER_H
#define PRESENTER_H

#include "quantity_ui.h"
#include "quantity.h"

struct presenter {
  QuantityUI *qtyUI;
  Quantity qty;
};

typedef struct presenter Presenter;

Presenter presenter_make(QuantityUI *qtyUI, const int initialValue);
void presenter_destroy(Presenter *p);

/* interface with the View */
void presenter_updateQuantity(Presenter *thePresenter, const int valueToAdd);

/* interface with the Model */
void presenter_addQuantity(Presenter *thePresenter, const int valueToAdd);
int presenter_getQuantity(Presenter *thePresenter);

#endif
