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

/** \brief adds a new value at the beginning of the list.
 *
 * \param list pointer to a list.
 * \param value value to be stored.
 */
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

/** \brief removes the last element of the list.
 *
 * \param list pointer to a list.
 */
void pop(list list) {
  if (list->first != NULL) {
    if (list->first == list->last) {
      free(list->last);
      list->first = NULL;
      list->last = NULL;

    } else {
      list->last = list->last->prev;
      free(list->last->next);
      list->last->next = NULL;
    }
  }
}
