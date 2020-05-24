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

/** \brief deletes the cache.
 *
 * \param cache cache to be deleted.
 */
void delete_cache(cache cache) {
  for (uint32_t i = 0; i < cache->capacity; ++i) {
    free(cache->buckets[i]);
  }

  delete_list(cache->queue);
  free(cache);
}

void put(cache cache, uint32_t key, uint32_t value) {
  uint32_t index;

  if (cache->current_capacity < cache->capacity) {
    // We have space in the cache, let's put the value into the queue.
    node element = enqueue(cache->queue, key, value);
    // Let's calculate the bucket index.
    index = hash(key) % cache->capacity;

    // First entry in the bucket
    if (cache->buckets[index] == NULL) {
      cache->buckets[index] = malloc(sizeof(bucket));
      cache->buckets[index]->entries = malloc(sizeof(entry));
      cache->current_capacity++;

    } else {
      remove_node(cache->queue, &cache->buckets[index]->entries->node);
    }

    cache->buckets[index]->entries->key = key;
    cache->buckets[index]->entries->value = value;
    cache->buckets[index]->entries->node = element;

  } else {
    // Cache is full, we need to evict an entry
  }
}
