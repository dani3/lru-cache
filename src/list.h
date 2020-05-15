#ifndef LIST_H
#define LIST_H

struct t_node {
  struct t_node* next;
  struct t_node* prev;
  int value;
};

struct t_list {
  struct t_node* first;
  struct t_node* last;
};

typedef struct t_node* node;
typedef struct t_list* list;

/// \brief creates a new list.
list new(void);

/// \brief adds a new element at the beginning of the list.
void add(list list, int value);

/// \brief removes the last element of the list.
void pop(list list);

#endif // LIST_H
