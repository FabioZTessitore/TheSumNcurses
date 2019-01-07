/* uiadapter.h */

#ifndef UIADAPTER_H
#define UIADAPTER_H

#include "quantity.h"
#include "quantity_ui.h"

QuantityUI *UIAdapter_makeAndRunUI(Quantity * const qty);
void UIAdapter_init();
QuantityUI *UIAdapter_createWin(Quantity * const qty);
void UIAdapter_mainloop(Quantity * const qty);
void UIAdapter_finalize(QuantityUI *qtyUI);

#endif
