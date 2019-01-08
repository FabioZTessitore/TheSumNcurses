/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "uiadapter.h"
#include "ioadapter.h"
#include "iotxtfile.h"

int main()
{
  IOAdapter *ioadapter = ioadapter_make(
      iotxtfile_readData,
      iotxtfile_writeData
  );

  int *initialValue = ioadapter->readData();

  UIAdapter_makeAndRunUI(*initialValue, ioadapter);

  free(initialValue);

  ioadapter_destroy(ioadapter);

  return 0;
}
