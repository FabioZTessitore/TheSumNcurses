/* ioadapter.c */

#include <stdlib.h>
#include "ioadapter.h"
#include "observer.h"

IOAdapter *ioadapter_make(void *(*readFunc)(), void (*writeFunc)(void * data))
{
  IOAdapter *ioadapter = (IOAdapter *)malloc(sizeof(IOAdapter));

  ioadapter->readData = readFunc;
  ioadapter->writeData = writeFunc;

  ioadapter->theObserver = observer_make((void *)ioadapter, ioadapter_update_storeData);

  return ioadapter;
}

void ioadapter_destroy(IOAdapter *ioadapter)
{
  if (ioadapter != NULL) {
    ioadapter->readData = NULL;
    ioadapter->writeData = NULL;
    observer_destroy(ioadapter->theObserver);
    free(ioadapter);
    ioadapter = NULL;
  }
}

void ioadapter_update_storeData(void *anIOAdapter, void *data)
{
  IOAdapter *ioadapter = (IOAdapter *)anIOAdapter;

  ioadapter->writeData(data);
}
