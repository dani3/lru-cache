#include "unity.h"

#include "list.h"

#define VALUE 0xA5

void setUp(void) {}

void tearDown(void) {}

void test_new_newEmptyListCreated(void) {
  list list = new();

  TEST_ASSERT_NULL(list->first);
  TEST_ASSERT_NULL(list->last);
}

void test_addWhenEmpty_elementAdded(void) {
  list list = new();

  add(list, VALUE);

  TEST_ASSERT_NOT_NULL(list->first);
  TEST_ASSERT_NOT_NULL(list->last);
  TEST_ASSERT_EQUAL_PTR(list->first, list->last);
  TEST_ASSERT_EQUAL_HEX(list->first->value, VALUE);
  TEST_ASSERT_NULL(list->first->next);
  TEST_ASSERT_NULL(list->first->prev);
}
