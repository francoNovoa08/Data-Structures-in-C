#include "binary_search_tree.h"
#include <stdlib.h>

BSTNode *BST_createNode(int value) {
    struct BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BSTNode* BST_insert(BSTNode *self, int value) {
    if (self == NULL) {
        return BST_createNode(value);
    }

    if (value < self->data) {
        self->left = BST_insert(self->left, value);
    }

    else if (value > self->data) {
        self->right = BST_insert(self->right, value);
    }

    return self;
}

bool BST_find(BSTNode *self, int value) {
    if (self == NULL) {
        return false;
    } else if (value == self->data) {
        return true;
    }

    if (value < self->data) {
        return BST_find(self->left, value);
    } else if (value > self->data) {
        return BST_find(self->right, value);
    }

    return false;
}

BSTNode* BST_delete(BSTNode *self, int value) {
    if (self == NULL) {
        return NULL;
    }
    
    if (self->data == value) {
        if (self->left == NULL && self->right == NULL) {
            free(self);
            return NULL;
        }
        
        if (self->right == NULL) {
            return self->left;
        }

        if (self->left == NULL) {
            return self->right;
        }

        BSTNode* current = self->right;
        while (current->left != NULL) {
            current = current->left;
        }

        self->data = current->data;
        self->right = BST_delete(self->right, current->data);
        return self;
    }



    if (self->data > value) {
        self->left = BST_delete(self->left, value);
    } else if (value > self->data) {
        self->right = BST_delete(self->right, value);
    }

    return self;
}

void BST_free(BSTNode *self) {
    if (self == NULL) {
        return;
    }
    BST_free(self->left);
    BST_free(self->right);
    free(self);
}