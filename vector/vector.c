#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void Vector_push(Vector *self, const int element) {
    if (self->size == self->capacity) {
        size_t new_capacity = self->capacity * 2;
        int *temp = realloc(self->array, new_capacity * sizeof(int));

        if (temp == NULL) {
            printf("Failed to allocate memory for larger Vector.");
            return;
        }

        self->array = temp;
        self->capacity = new_capacity;
    }

    self->array[self->size] = element;
    self->size++;
}

int Vector_pop(Vector *self) {
    if (self->size == 0) {
        return 0;
    }

    int value = self->array[self->size - 1];
    self->size--;
    return value;
}

int Vector_get(const Vector *self, const size_t index) {
    if (index >= self->size) {
        printf("Get failed: Out of bounds");
        return 0;
    }

    return self->array[index];
}

void Vector_set(Vector *self, const size_t index, const int value) {
    if (index >= self->size) {
        printf("Set failed: Out of bounds");
        return;
    }

    self->array[index] = value;
}

void Vector_free(Vector *self) {
    free(self->array);
    self->array = NULL;
    self->size = 0;
    self->capacity = 0;
}

Vector Vector_init(size_t capacity) {
    if (capacity == 0) {
        capacity = 1;
    }
    int *temp = malloc(capacity * sizeof(int));

    if (temp == NULL) {
        printf("Failed to allocate memory for new Vector.");
        Vector empty_vector = {0, 0, NULL};
        return empty_vector;
    }

    Vector vector;
    vector.capacity = capacity;
    vector.size = 0;
    vector.array = temp;

    return vector;
}
