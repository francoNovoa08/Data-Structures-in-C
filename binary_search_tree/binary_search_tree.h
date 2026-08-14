#include <stdbool.h>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

/**
 * @brief Adds an element with a given value to the BST
 *
 * @param self Pointer to the BST root node struct
 * @param value Element to be pushed
 **/
BSTNode* BST_insert(BSTNode *self, int value);

/**
 * @brief Checks if an element exists in a BST
 *
 * @param self Pointer to the BST root node struct
 * @param value Element to find
 *
 * @return true if the element is in the BST; false if it isn't
 **/
bool BST_find(BSTNode *self, int value);

/**
 * @brief Removes an element from the BST
 *
 * @param self Pointer to the BST root node struct
 * @param value Element to remove
 **/
BSTNode* BST_delete(BSTNode *self, int value);

/**
 * @brief Creates a BST node with a given value
 *
 * @param value Value to be stored in the node
 *
 * @return The created node struct
 **/
BSTNode* BST_createNode(int value);

/**
 * @brief Frees the BST's memory
 *
 * @param self Pointer to the BST root node struct
 **/
void BST_free(BSTNode *self);

#endif // BINARY_SEARCH_TREE_H