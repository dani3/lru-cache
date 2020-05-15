#include <stdlib.h>

#include "list.h"

/** \brief creates a new list.
 *
 * \return pointer to list.
 */
list new(void) {
  list list = malloc(sizeof(list));

  list->first = NULL;
  list->first = NULL;

  return list;
}

void add(list list, int value) {

}
