/* iotxtfile.c */

#include <stdio.h>
#include <stdlib.h>
#include "iotxtfile.h"

static char *filename = "sum.dat";

void *iotxtfile_readData()
{
  FILE *f = fopen(filename, "r");
  int *value = (int *)malloc(sizeof(int));

  if (!f) {
    *value = 0;
  } else {
    fscanf(f, "%d", value);
    fclose(f);
  }

  return value;
}

void iotxtfile_writeData(void *data)
{
  FILE *f = fopen(filename, "w");
  int *dataInt = (int *)data;

  fprintf(f, "%d\n", *dataInt);

  fclose(f);
}
