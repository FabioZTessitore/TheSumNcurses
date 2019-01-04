/* observer.c */

#include <stdlib.h>
#include "observer.h"

#include <stdio.h>

Observer *observer_make(void *parent, void (*notify)(void *, void *))
{
  Observer *this = (Observer *)malloc(sizeof(Observer));

  this->parent = parent;
	this->notify = notify;

  return this;
}

void observer_destroy(Observer *theObserver)
{
  if (theObserver != NULL) {
    theObserver->parent = NULL;
    theObserver->notify = NULL;
    free(theObserver);
    theObserver = NULL;
  }
}

void observer_update(Observer *theObserver, void *data)
{
  if (theObserver==NULL) {
    printf("observer is NULL\n");
  }

  if (theObserver->parent == NULL) {
    printf("parent is null");
  }
  theObserver->notify(theObserver->parent, data);
}
