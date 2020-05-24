#include "unity.h"

#include "cache.h"
#include "list.h"

cache dut;

void setUp(void) {
  dut = new_cache(16);
}

void tearDown(void) {
  delete_cache(dut);
}

void test_newCache_cacheCreated(void) {
  TEST_ASSERT_NOT_NULL(dut);
  TEST_ASSERT_NOT_NULL(dut->queue);
  TEST_ASSERT_NOT_NULL(dut->buckets);
  TEST_ASSERT_EQUAL_INT(16, dut->capacity);
  TEST_ASSERT_EQUAL_INT(0, dut->current_capacity);

  for (uint32_t i = 0; i < 16; ++i) {
      TEST_ASSERT_NULL(dut->buckets[i]);
  }
}

void test_putNewElementWhenEmpty_elementAdded(void) {
  put(dut, 0xA50FF00, 0x11223344);

  TEST_ASSERT_EQUAL_INT(1, dut->current_capacity);
}
