#include <stdlib.h>

#include "list.h"

static node create_node(int value) {
  node node = malloc(sizeof(node));

  node->next = NULL;
  node->prev = NULL;
  node->value = value;

  return node;
}

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
  // Let's create a node first.
  node node = create_node(value);

  if (list->first == NULL) {
    list->first = node;
    list->last = node;

  } else {
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }
}
