/* subject.c */

#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
#include "observer.h"

#include <ncurses.h>

Subject *subject_make()
{
  Subject *this = (Subject *)malloc(sizeof(Subject));

  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    this->observers[i] = NULL;
  }

  return this;
}

void subject_destroy(Subject *theSubject)
{
  int i;

  if (theSubject != NULL) {
    for (i = 0; i < MAX_OBSERVERS; i++) {
      if (theSubject->observers[i] != NULL) {
        theSubject->observers[i] = NULL;
      }
    }
    free(theSubject);
    theSubject = NULL;
  }
}

void subject_attach(Subject * const theSubject, Observer * const theObserver)
{
  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    if (theSubject->observers[i] == NULL) {
      theSubject->observers[i] = theObserver;
      return;
    }
  }

  printf("Error: unable to attach the Observer\n");
}

void subject_notify(const Subject * const theSubject, void *data)
{
  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    if (theSubject->observers[i] != NULL) {

      if (theSubject == NULL) {
        mvprintw(0, 0, "SUBJECT NOTIFY (%d): Subject is NULL\n", i);
        printf("SUBJECT NOTIFY (%d): Subject is NULL\n", i);
      }
      observer_update(theSubject->observers[i], data);
    }
  }
}
