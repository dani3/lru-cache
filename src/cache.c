#include <stdlib.h>
#include <stdio.h>

#include "cache.h"

static uint32_t hash(uint32_t key) {
  key = ((key >> 16) ^ key) * 0x45d9f3b;
  key = ((key >> 16) ^ key) * 0x45d9f3b;
  key = (key >> 16) ^ key;

  return key;
}

/** \brief creates a new cache.
 *
 * \param capacity number of entries the cache can store.
 *
 * \return pointer to cache.
 */
cache new_cache(uint32_t capacity) {
  cache cache = malloc(sizeof(cache));

  cache->buckets = malloc(sizeof(bucket) * capacity);
  cache->queue = new_list();
  cache->capacity = capacity;
  cache->current_capacity = 0;

  for (uint32_t i = 0; i < capacity; ++i) {
    cache->buckets[i] = NULL;
  }

  return cache;
}

void put(cache cache, uint32_t key, uint32_t value) {
  uint32_t index;

  if (cache->capacity < cache->current_capacity) {
    // We have space in the cache, let's put the value into the queue.
    enqueue(cache->queue, key, value);
    // Let's calculate the bucket index.
    index = hash(key) % cache->capacity;

    // First entry in the bucket
    if (cache->buckets[index] == NULL) {


    } else {

    }

  } else {
    // Cache is full, we need to evict an entry
  }
}
