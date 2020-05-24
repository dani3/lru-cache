#include "unity.h"

#include "list.h"

#define KEY           0xC5
#define ANOTHER_KEY   0x5C

#define VALUE         0xA5
#define ANOTHER_VALUE 0x5A

void setUp(void) {}

void tearDown(void) {}

void test_new_newEmptyListCreated(void) {
  list list = new_list();

  TEST_ASSERT_NULL(list->first);
  TEST_ASSERT_NULL(list->last);
}

void test_addWhenEmpty_elementAdded(void) {
  list list = new_list();

  node node = enqueue(list, KEY, VALUE);

  TEST_ASSERT_NOT_NULL(list->first);
  TEST_ASSERT_NOT_NULL(list->last);

  TEST_ASSERT_EQUAL_PTR(list->first, list->last);

  TEST_ASSERT_EQUAL_HEX(node->key, KEY);
  TEST_ASSERT_EQUAL_HEX(node->value, VALUE);
  TEST_ASSERT_EQUAL_HEX(list->first->key, KEY);
  TEST_ASSERT_EQUAL_HEX(list->first->value, VALUE);

  TEST_ASSERT_NULL(list->first->next);
  TEST_ASSERT_NULL(list->first->prev);
}

void test_addWhenNotEmtpy_elementAdded(void) {
  list list = new_list();

  node node1 = enqueue(list, KEY, VALUE);
  node node2 = enqueue(list, ANOTHER_KEY, ANOTHER_VALUE);

  TEST_ASSERT_NOT_NULL(list->first);
  TEST_ASSERT_NOT_NULL(list->last);

  TEST_ASSERT_FALSE(list->first == list->last);

  TEST_ASSERT_EQUAL_HEX(node1->key, KEY);
  TEST_ASSERT_EQUAL_HEX(node1->value, VALUE);
  TEST_ASSERT_EQUAL_HEX(node2->key, ANOTHER_KEY);
  TEST_ASSERT_EQUAL_HEX(node2->value, ANOTHER_VALUE);
  TEST_ASSERT_EQUAL_HEX(list->first->key, ANOTHER_KEY);
  TEST_ASSERT_EQUAL_HEX(list->first->value, ANOTHER_VALUE);
  TEST_ASSERT_EQUAL_HEX(list->last->key, KEY);
  TEST_ASSERT_EQUAL_HEX(list->last->value, VALUE);

  TEST_ASSERT_EQUAL_PTR(list->first->next, node1);
  TEST_ASSERT_EQUAL_PTR(list->last->prev, node2);

  TEST_ASSERT_EQUAL_PTR(node1->prev, node2);
  TEST_ASSERT_EQUAL_PTR(node2->next, node1);

  TEST_ASSERT_NULL(node1->next);
  TEST_ASSERT_NULL(node2->prev);
  TEST_ASSERT_NULL(list->last->next);
  TEST_ASSERT_NULL(list->first->prev);
}

void test_popWhenEmpty_nothingHappens(void) {
  list list = new_list();

  dequeue(list);

  TEST_ASSERT_NULL(list->first);
  TEST_ASSERT_NULL(list->last);
}

void test_popWithOneElement_listIsEmpty(void) {
  list list = new_list();
  enqueue(list, KEY, VALUE);

  dequeue(list);

  TEST_ASSERT_NULL(list->first);
  TEST_ASSERT_NULL(list->last);
}

void test_popWithTwoElements_listContainsOneElement(void) {
  list list = new_list();
  enqueue(list, KEY, VALUE);
  enqueue(list, ANOTHER_KEY, ANOTHER_VALUE);

  dequeue(list);

  TEST_ASSERT_NOT_NULL(list->first);
  TEST_ASSERT_NOT_NULL(list->last);

  TEST_ASSERT_EQUAL_PTR(list->first, list->last);

  TEST_ASSERT_NULL(list->first->next);
  TEST_ASSERT_NULL(list->first->prev);

  TEST_ASSERT_EQUAL_HEX(list->first->key, ANOTHER_KEY);
  TEST_ASSERT_EQUAL_HEX(list->first->value, ANOTHER_VALUE);
}

void test_removeOnlyElement_nodeRemovedAndListIsEmtpy(void) {
  list list = new_list();
  node node = enqueue(list, KEY, VALUE);

  remove_node(list, &node);

  TEST_ASSERT_NULL(node);
  TEST_ASSERT_NULL(list->first);
  TEST_ASSERT_NULL(list->last);
}

void test_removeFirstElement_nodeRemovedAndListContainsOneElement(void) {
  list list = new_list();
  node node1 = enqueue(list, KEY, VALUE);
  node node2 = enqueue(list, ANOTHER_KEY, ANOTHER_VALUE);

  remove_node(list, &node2);

  TEST_ASSERT_NULL(node2);
  TEST_ASSERT_NULL(node1->prev);
  TEST_ASSERT_NULL(node1->next);

  TEST_ASSERT_EQUAL_PTR(list->first, node1);
  TEST_ASSERT_EQUAL_PTR(list->last, node1);
}

void test_removeLastElement_nodeRemovedAndListContainsOneElement(void) {
  list list = new_list();
  node node1 = enqueue(list, KEY, VALUE);
  node node2 = enqueue(list, ANOTHER_KEY, ANOTHER_VALUE);

  remove_node(list, &node1);

  TEST_ASSERT_NULL(node1);
  TEST_ASSERT_NULL(node2->prev);
  TEST_ASSERT_NULL(node2->next);

  TEST_ASSERT_EQUAL_PTR(list->first, node2);
  TEST_ASSERT_EQUAL_PTR(list->last, node2);
}

void test_removeMiddleElement_nodeRemovedAndListContainsTwoElements(void) {
  list list = new_list();
  node node1 = enqueue(list, KEY, VALUE);
  node node2 = enqueue(list, ANOTHER_KEY, ANOTHER_VALUE);
  node node3 = enqueue(list, ANOTHER_KEY, ANOTHER_VALUE);

  remove_node(list, &node2);

  TEST_ASSERT_NULL(node2);

  TEST_ASSERT_EQUAL_PTR(node1->prev, node3);
  TEST_ASSERT_EQUAL_PTR(node3->next, node1);

  TEST_ASSERT_EQUAL_PTR(list->first, node3);
  TEST_ASSERT_EQUAL_PTR(list->last, node1);
}
