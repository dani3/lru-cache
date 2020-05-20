#include <stdlib.h>

#include "list.h"

static node create_node(uint32_t key, uint32_t value) {
  node node = malloc(sizeof(node));

  node->next = NULL;
  node->prev = NULL;
  node->key = key;
  node->value = value;

  return node;
}

/** \brief creates a new list.
 *
 * \return pointer to list.
 */
list new_list(void) {
  list list = malloc(sizeof(list));

  list->first = NULL;
  list->first = NULL;

  return list;
}

/** \brief adds a new value at the beginning of the list.
 *
 * \param list pointer to a list.
 * \param key key associated to the value.
 * \param value value to be stored.
 */
void enqueue(list list, uint32_t key, uint32_t value) {
  // Let's create a node first.
  node node = create_node(key, value);

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
void dequeue(list list) {
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
