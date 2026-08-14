#include <stdint.h>
#include <stdio.h>


#ifndef HASHMAP_H
#define HASHMAP_H

#define KNUTH_32 2654435769U

typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    size_t capacity;
    size_t size;
    size_t table_bits;
} HashMap;

/**
 * @brief Adds an element with a given key and value to the HashMap
 *
 * @param self Pointer to the hashmap struct
 * @param value Element to be pushed
 **/
void HashMap_put(HashMap *self, int *key, int value);

/**
 * @brief Returns an element with a given key
 *
 * @param self Pointer to the hashmap struct
 * @param key The key whose element to return
 *
 * @return The value at the given key
 **/
int *HashMap_get(HashMap *self, int *key);

/**
 * @brief Removes and returns element with a given key
 *
 * @param self Pointer to the hashmap struct
 * @param key The key whose element to remove
 *
 * @return The value at the given key
 **/
int HashMap_remove(HashMap *self, int *key);

/**
 * @brief Free's the HashMap's memory
 *
 * @param self Pointer to the hashmap struct
 **/
void HashMap_free(HashMap *self);

/**
 * Multiplicative hash function
 * @param key: The 32-bit integer to hash
 * @param table_bits: The power of 2 for table size (e.g., 8 bits = table size
 * of 256)
 * @return An index in the range [0, 2^table_bits - 1]
 **/
uint32_t multiplicative_hash(const int *key, uint8_t table_bits);

/**
 * @brief Creates a hashmap
 *
 * @returns An empty hashmap
 **/
HashMap HashMap_init();

#endif // HASHMAP_H