#ifndef LIST_H
#define LIST_H
#include <stdint.h>

struct t_node {
  struct t_node* next;
  struct t_node* prev;
  uint32_t key;
  uint32_t value;
};

struct t_list {
  struct t_node* first;
  struct t_node* last;
};

typedef struct t_node* node;
typedef struct t_list* list;

/// \brief creates a new list.
list new_list(void);

/// \brief deletes the list.
void delete_list(list list);

/// \brief adds a new element at the beginning of the list.
node enqueue(list list, uint32_t key, uint32_t value);

/// \brief removes the last element of the list.
void dequeue(list list);

/// \brief removes the node from the list.
void remove_node(list list, node* node);

#endif // LIST_H
