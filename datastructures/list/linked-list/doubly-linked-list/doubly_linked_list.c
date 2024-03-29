#include <stdlib.h>
#include "doubly_linked_list.h"

DoublyLinkedList *createList(DoublyLinkedNode *head,
                             DoublyLinkedNode *tail) {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->head = head;
    list->tail = tail;
    return list;
}

DoublyLinkedNode *createNode(int data, 
                             DoublyLinkedNode *previous,
                             DoublyLinkedNode *next) {
    DoublyLinkedNode *node = malloc(sizeof(DoublyLinkedNode));
    node->data = data;
    node->previous = previous;
    node->next = next;
    return node;
}

void insertBefore(DoublyLinkedNode *newNode,
                  DoublyLinkedNode *node, 
                  DoublyLinkedList *list) {
    if (node->previous == NULL) {
        list->head = newNode;
    } else {
        newNode->previous = node->previous;
        newNode->previous->next = newNode;
    }
    node->previous = newNode;
    newNode->next = node;
}

void insertBeginning(DoublyLinkedNode *newNode, DoublyLinkedList *list) {
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    } else {
        insertBefore(newNode, list->head, list);
    }
}

void insertAfter(DoublyLinkedNode *newNode,
                 DoublyLinkedNode *node,
                 DoublyLinkedList *list) {
    if (node->next == NULL) {
        list->tail = newNode;
    } else {
        newNode->next = node->next;
        newNode->next->previous = newNode;
    }
    node->next = newNode;
    newNode->previous = node;
}
                                                              
void insertEnd(DoublyLinkedNode *newNode, DoublyLinkedList *list) {
    if (list->tail == NULL) {
        insertBeginning(newNode, list);
    } else {
        insertAfter(newNode, list->tail, list);
    }
}

void removeNode(DoublyLinkedNode *nodeToRemove, DoublyLinkedList *list) {
    if (nodeToRemove->previous == NULL) {
        list->head = nodeToRemove->next;
    } else {
        nodeToRemove->previous->next = nodeToRemove->next;
    }
    if (nodeToRemove->next == NULL) {
        list->tail = nodeToRemove->previous;
    } else {
        nodeToRemove->next->previous = nodeToRemove->previous;
    }
}
