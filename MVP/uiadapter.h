/* uiadapter.h */

#ifndef UIADAPTER_H
#define UIADAPTER_H

#include "quantity_ui.h"
#include "presenter.h"
#include "ioadapter.h"

QuantityUI *UIAdapter_makeAndRunUI(const int initialValue, IOAdapter *ioadapter);
void UIAdapter_init();
QuantityUI *UIAdapter_createWin(const int initialValue);
void UIAdapter_mainloop(Presenter *p);
void UIAdapter_finalize(QuantityUI *qtyUI);

#endif
