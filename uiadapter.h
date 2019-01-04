/* uiadapter.h */

#ifndef UIADAPTER_H
#define UIADAPTER_H

#include "quantity.h"

void UIAdapter_init();
void UIAdapter_finalize();
void UIAdapter_createWin(Quantity * const qty);
void UIAdapter_mainloop();
void UIAdapter_makeAndRunUI(Quantity * const qty);

#endif
