#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t length;

} LinkedList;

/**
 * @brief Pushes an element into the linked list at the front
 *
 * @param self Pointer to the linked list struct
 * @param value Element to be pushed
 **/
void LinkedList_push_front(LinkedList *self, const int value);

/**
 * @brief Pushes an element into the linked list at the back
 *
 * @param self Pointer to the linked list struct
 * @param value Element to be pushed
 **/
void LinkedList_push_back(LinkedList *self, const int value);

/**
 * @brief Removes and returns the element of the linked list at the front
 *
 * @param self Pointer to the Vector struct
 *
 * @return The value popped from the Vector
 **/
int LinkedList_pop_front(LinkedList *self);

/**
 * @brief Removes and returns the element of the linked list at the back
 *
 * @param self Pointer to the Vector struct
 *
 * @return The value popped from the Vector
 **/
int LinkedList_pop_back(LinkedList *self);

/**
 * @brief Returns the element of the linked list at a given index
 *
 * @param self Pointer to the linked list struct
 * @param index The index from which to get the element
 *
 * @return The value at the given index or 0 if the linked list is empty
 **/
int LinkedList_get(LinkedList *self, const size_t index);

/**
 * @brief Removes and returns the element of the linked list at a given index
 *
 * @param self Pointer to the linked list struct
 * @param index The index from which to get the element
 *
 * @return The value at the given index or 0 if the linked list is empty
 **/
int LinkedList_pop(LinkedList *self, const size_t index);

/**
 * @brief Frees the memory used by the linked list on the heap
 *
 * @param self Pointer to the linked list struct
 **/
void LinkedList_free(LinkedList *self);

/**
 * @brief Creates a linked list
 *
 * @returns An empty linked list
 **/
LinkedList LinkedList_init();

#endif // LINKED_LIST_H