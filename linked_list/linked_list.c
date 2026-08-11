#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void LinkedList_push_front(LinkedList *self, const int value) {
  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    printf("New node memory allocation failed.");
    return;
  }

  new_node->data = value;
  new_node->prev = NULL;
  new_node->next = self->head;

  if (self->length == 0) {
    self->head = new_node;
    self->tail = new_node;
    self->length++;
    return;
  }

  self->head->prev = new_node;
  self->head = new_node;
  self->length++;
}

void LinkedList_push_back(LinkedList *self, const int value) {
  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    printf("New node memory allocation failed.");
    return;
  }

  new_node->data = value;
  new_node->prev = self->tail;
  new_node->next = NULL;

  if (self->length == 0) {
    self->head = new_node;
    self->tail = new_node;
    self->length++;
    return;
  }

  self->tail->next = new_node;
  self->tail = new_node;
  self->length++;
}

int LinkedList_pop_front(LinkedList *self) {
  if (self->length == 0) {
    return 0;
  }

  Node *head_pointer = self->head;
  int value = head_pointer->data;
  self->head = self->head->next;

  if (self->length == 1) {
    self->tail = NULL;
  } else {
    self->head->prev = NULL;
  }

  free(head_pointer);
  self->length--;
  return value;
}

int LinkedList_pop_back(LinkedList *self) {
  if (self->length == 0) {
    return 0;
  }
  Node *tail_pointer = self->tail;
  int value = self->tail->data;
  self->tail = self->tail->prev;

  if (self->length == 1) {
    self->head = NULL;
  } else {
    self->tail->next = NULL;
  }

  free(tail_pointer);
  self->length--;
  return value;
}

int LinkedList_get(LinkedList *self, const size_t index) {
  if (self->length == 0 || index >= self->length) {
    return 0;
  }

  size_t counter = 0;
  Node *current;

  if (index < self->length / 2) {
    current = self->head;
    while (counter < index) {
      current = current->next;
      counter++;
    }

    return current->data;
  } else {
    current = self->tail;
    size_t modified_index = (self->length - 1) - index;
    while (counter < modified_index) {
      current = current->prev;
      counter++;
    }

    return current->data;
  }
}

int LinkedList_pop(LinkedList *self, const size_t index) {
  if (self->length == 0 || index >= self->length) {
    return 0;
  }

  if (index == 0) {
    return LinkedList_pop_front(self);
  }
  if (index == self->length - 1) {
    return LinkedList_pop_back(self);
  }

  size_t counter = 0;
  int value;
  Node *current;

  if (index < self->length / 2) {
    current = self->head;
    while (counter < index) {
      current = current->next;
      counter++;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    value = current->data;

    free(current);
    self->length--;
    return value;
  } else {
    current = self->tail;
    size_t modified_index = (self->length - 1) - index;
    while (counter < modified_index) {
      current = current->prev;
      counter++;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    value = current->data;

    free(current);
    self->length--;
    return value;
  }
}

void LinkedList_free(LinkedList *self) {
  if (self->length == 0) {
    return;
  }

  Node *current = self->head;
  Node *next = current->next;
  for (size_t _ = 0; _ < self->length; _++) {
    free(current);
    current = next;
    if (current != NULL) {
      next = current->next;
    }
  }
  self->head = NULL;
  self->tail = NULL;
  self->length = 0;
}

LinkedList LinkedList_init() {
  LinkedList list = {NULL, NULL, 0};
  return list;
}