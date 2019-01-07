/* ioadapter.h */

#ifndef IOADAPTER_H
#define IOADAPTER_H

#include "observer.h"

struct ioadapter {
  void * (*readData)();
  void (*writeData)(void *data);
  Observer *theObserver;
};

typedef struct ioadapter IOAdapter;

/* ioadapeter_make() must return a pointer
 * cause of the Observer that need it
 */
IOAdapter *ioadapter_make(void *(*readFunc)(), void (*writeFunc)(void * data));
void ioadapter_destroy(IOAdapter *ioadapter);

void ioadapter_update_storeData(void *anIOAdapter, void *data);

#endif
