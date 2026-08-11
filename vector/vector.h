#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  size_t size;
  size_t capacity;
  int *array;
} Vector;

/**
 * @brief Pushes an element into the Vector at the end
 *
 * @pre Vector must not be NULL
 * @pre size must be greater than or equal to 0
 *
 * @param self Pointer to the Vector struct
 * @param element Element to be pushed
 **/
void Vector_push(Vector *self, const int element);

/**
 * @brief Pops and returns the element of the Vector at the end
 *
 * @pre Vector must not be NULL
 * @pre size must be greater than or equal to 0
 *
 * @param self Pointer to the Vector struct
 *
 * @return The value popped from the Vector
 **/
int Vector_pop(Vector *self);

/**
 * @brief Returns the element of the Vector at a given index
 *
 * @pre Vector must not be NULL
 * @pre size must be greater than or equal to 0
 *
 * @param self Pointer to the Vector struct
 * @param index The index from which to get the element
 *
 * @return The value at the given index or 0 if the Vector is empty
 **/
int Vector_get(const Vector *self, const size_t index);

/**
 * @brief Sets the element of the Vector at the at the given index to a given
 * value
 *
 * @pre Vector must not be NULL
 * @pre size must be greater than or equal to 0
 *
 * @param self Pointer to the Vector struct
 * @param index The index where a value is written to
 * @param value The value to be added to the Vector
 **/
void Vector_set(Vector *self, const size_t index, const int value);

/**
 * @brief Frees the memory used by the Vector on the heap
 *
 * @param self Pointer to the Vector struct
 **/
void Vector_free(Vector *self);

/**
 * @brief Creates a Vector with a given size
 *
 * @param capacity The size of the created Vector
 *
 * @returns The created Vector.
 * @returns A Vector with capacity and size 0 and NULL array if memory
 * allocation fails.
 **/
Vector Vector_init(size_t capacity);

#endif // VECTOR_H