#include <stdlib.h>
#include <stdio.h>

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

/** \brief deletes the list.
 *
 * \param list list to be deleted.
 */
void delete_list(list list) {
  node current = list->first;
  node next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  free(list);
}

/** \brief adds a new value at the beginning of the list.
 *
 * \param list pointer to a list.
 * \param key key associated to the value.
 * \param value value to be stored.
 *
 * \return node.
 */
node enqueue(list list, uint32_t key, uint32_t value) {
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

  return node;
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

/** \brief removes a certain node from the list.
 *
 * \param list list to remove the node from.
 * \param node node to be removed.
 */
void remove_node(list list, node* node) {
  if (((*node) == NULL) || (list->first == NULL)) {
    return;
  }

  // It's the only element.
  if ((list->first == (*node)) && (list->last == (*node))) {
    list->first = NULL;
    list->last = NULL;

  } else {
    // It's not tne only element.
    // It's the first element.
    if ((*node)->prev == NULL) {
      list->first = (*node)->next;
      (*node)->next->prev = NULL;

    } else if ((*node)->next == NULL) {
      // It's the last element.
      list->last = (*node)->prev;
      (*node)->prev->next = NULL;

    } else {
      // The element is in the middle.
      (*node)->prev->next = (*node)->next;
      (*node)->next->prev = (*node)->prev;
    }
  }


  free(*node);
  *node = NULL;
}
