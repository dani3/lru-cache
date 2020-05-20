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

  enqueue(list, KEY, VALUE);

  TEST_ASSERT_NOT_NULL(list->first);
  TEST_ASSERT_NOT_NULL(list->last);
  TEST_ASSERT_EQUAL_PTR(list->first, list->last);
  TEST_ASSERT_EQUAL_HEX(list->first->value, VALUE);
  TEST_ASSERT_EQUAL_HEX(list->first->key, KEY);
  TEST_ASSERT_NULL(list->first->next);
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
