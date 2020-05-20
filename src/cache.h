#ifndef CACHE_H
#define CACHE_H
#include <stdint.h>

#include "list.h"

struct t_entry {
  struct entry* next;
  uint32_t key;
  uint32_t value;
};

typedef struct t_entry* entry;

struct t_bucket {
  entry entries;
};

typedef struct t_bucket* bucket;

struct t_cache {
  uint32_t capacity;
  uint32_t current_capacity;
  bucket* buckets;
  list queue;
};

typedef struct t_cache* cache;

/// \brief creates a new cache.
cache new_cache(uint32_t capacity);

void put(cache cache, uint32_t key, uint32_t value);

#endif // CACHE_H
