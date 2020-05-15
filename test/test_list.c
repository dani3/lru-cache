#include "unity.h"

#include "list.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_list_newListCreated(void) {
    list list = new();

    TEST_ASSERT_NULL(list->first);
    TEST_ASSERT_NULL(list->last);
}
