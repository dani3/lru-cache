#include "unity.h"

#include "cache.h"
#include "list.h"

void setUp(void) {}

void tearDown(void) {}

void test_newCache_cacheCreated(void) {
    cache cache = new_cache(10);

    TEST_ASSERT_NOT_NULL(cache);
    TEST_ASSERT_NOT_NULL(cache->queue);
    TEST_ASSERT_NOT_NULL(cache->buckets);
    TEST_ASSERT_EQUAL_INT(cache->capacity, 10);
    TEST_ASSERT_EQUAL_INT(cache->current_capacity, 0);

    for (uint32_t i = 0; i < 10; ++i) {
        TEST_ASSERT_NULL(cache->buckets[i]);
    }
}
