#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

void resize(HashMap *self);

void HashMap_put(HashMap *self, int *key, int value) {
    if (self == NULL || key == NULL)
        return;

    uint32_t index = multiplicative_hash(key, self->table_bits);

    HashNode *node = malloc(sizeof(HashNode));

    if (node == NULL) {
        printf("Failed to allocate memory for new HasHnode.");
        return;
    }

    node->key = *key;
    node->value = value;
    node->next = NULL;

    HashNode *current = self->buckets[index];

    if (current == NULL) {
        self->buckets[index] = node;
        self->size++;
        if (self->size > 0.75 * self->capacity) {
            resize(self);
        }
        return;
    }

    HashNode *last_non_null = current;
    while (current != NULL) {
        if (current->key == *key) {
            current->value = value;
            free(node);
            return;
        }

        current = current->next;

        if (current != NULL)
            last_non_null = current;
    }

    last_non_null->next = node;
    self->size++;
    if (self->size > 0.75 * self->capacity) {
        resize(self);
    }
}

void resize(HashMap *self) {
    HashNode **new_buckets = calloc(self->capacity * 2, sizeof(HashNode *));
    size_t table_bits = self->table_bits + 1;

    if (new_buckets == NULL) {
        printf("Failed to allocate memory for resized Hashmap.");
        return;
    }

    HashNode **buckets = self->buckets;
    HashNode *bucket;
    HashNode *next;
    uint32_t index;
    for (size_t i = 0; i < self->capacity; i++) {
        bucket = buckets[i];
        if (bucket == NULL) {
            continue;
        }

        while (bucket != NULL) {
            index = multiplicative_hash(&bucket->key, table_bits);
            next = bucket->next;

            bucket->next = new_buckets[index];
            new_buckets[index] = bucket;

            bucket = next;
        }
    }

    free(buckets);
    self->capacity *= 2;
    self->table_bits = table_bits;
    self->buckets = new_buckets;
}

int *HashMap_get(HashMap *self, int *key) {
    if (self == NULL || key == NULL)
        return NULL;

    uint32_t index = multiplicative_hash(key, self->table_bits);

    HashNode *current = self->buckets[index];

    while (current != NULL) {
        if (current->key == *key) {
            return &(current->value);
        }
        current = current->next;
    }

    return NULL;
}

int HashMap_remove(HashMap *self, int *key) {
    if (self == NULL || key == NULL)
        return NULL;

    uint32_t index = multiplicative_hash(key, self->table_bits);

    HashNode *current = self->buckets[index];

    if (current == NULL)
        return NULL;

    if (current->next == NULL && current->key == *key) {
        int value = current->value;
        free(current);
        self->size--;
        self->buckets[index] = NULL;
        return value;
    }

    HashNode *last_node = NULL;
    while (current != NULL) {
        if (current->key == *key) {
            int value = current->value;
            if (last_node == NULL)
                self->buckets[index] = current->next;
            else
                last_node->next = current->next;

            free(current);
            self->size--;
            return value;
        }
        last_node = current;
        current = current->next;
    }

    return -1;
}

void HashMap_free(HashMap *self) {
    HashNode *current;
    HashNode *next;
    for (size_t i = 0; i < self->capacity; i++) {
        current = self->buckets[i];

        if (current == NULL)
            continue;

        next = current->next;

        while (current != NULL) {
            free(current);
            current = next;
            if (current != NULL) {
                next = current->next;
            }
        }
    }
    free(self->buckets);
    self->buckets = NULL;
}

HashMap HashMap_init() {
    size_t capacity = 16;
    size_t table_bits = 4;
    HashNode **temp = calloc(capacity, sizeof(HashNode *));

    if (temp == NULL) {
        printf("Failed to allocate memory for new HashMap.");
        HashMap empty_map = {NULL, capacity, 0};
        return empty_map;
    }

    HashMap map;
    map.size = 0;
    map.capacity = capacity;
    map.buckets = temp;
    map.table_bits = table_bits;

    return map;
}

uint32_t multiplicative_hash(const int *key, uint8_t table_bits) {
    if (key == NULL)
        return 0;

    uint32_t key_val = (uint32_t)(*key);

    return (key_val * KNUTH_32) >> (32 - table_bits);
}