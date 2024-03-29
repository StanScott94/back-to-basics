#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"

#define VERIFY(s, i) (printf("%s %s", s, (i) ? "successful\n" : "failed\n"))

void testCreateNode() {
    DoublyLinkedNode *node = createNode(10, NULL, NULL);
    
    bool expected = node->data == 10 &&
                    node->previous == NULL &&
                    node->next == NULL;
    
    free(node);
    
    VERIFY("testCreateNode", expected);
}

void testInsertBeginning(DoublyLinkedList *list) {
    list = createList(NULL, NULL);
    
    DoublyLinkedNode *nodeA = createNode(20, NULL, NULL);
    DoublyLinkedNode *nodeB = createNode(10, NULL, NULL);
    
    insertBeginning(nodeA, list);
    insertBeginning(nodeB, list);
    
    bool expected = list->head->data == 10 &&
                    list->head->previous == NULL &&
                    list->head->next == nodeA &&
                    list->tail->data == 20 &&
                    list->tail->next == NULL &&
                    list->tail->previous == nodeB;

    free(nodeA);
    free(nodeB);

    VERIFY("testInsertBeginning", expected);
}

void testInsertEnd(DoublyLinkedList *list) {
    list = createList(NULL, NULL);
    
    DoublyLinkedNode *nodeA = createNode(200, NULL, NULL);
    DoublyLinkedNode *nodeB = createNode(100, NULL, NULL);
            
    insertEnd(nodeA, list);
    insertEnd(nodeB, list);
                    
    bool expected = list->head->data == 200 &&
                    list->head->previous == NULL &&
                    list->head->next == nodeB &&
                    list->tail->data == 100 &&
                    list->tail->next == NULL &&
                    list->tail->previous == nodeA;

    free(nodeA);
    free(nodeB);

    VERIFY("testInsertEnd", expected);
}

void testRemove(DoublyLinkedList *list) {
    list = createList(NULL, NULL);
    
    DoublyLinkedNode *nodeA = createNode(200, NULL, NULL);
    DoublyLinkedNode *nodeB = createNode(100, NULL, NULL);
            
    insertEnd(nodeA, list);
    insertEnd(nodeB, list);
    removeNode(nodeB, list);

    bool expected = list->head->data == 200 &&
        list->head->previous == NULL &&
        list->head->next == NULL &&
        list->tail->data == 200;

    VERIFY("testRemove B", expected);

    insertEnd(nodeB, list);
    removeNode(nodeA, list);
        
    expected = list->head->data == 100 &&
        list->head->previous == NULL &&
        list->head->next == NULL &&
        list->tail->data == 100;

    VERIFY("testRemove A", expected);

    free(nodeA);
    free(nodeB);
}

int main() {
    DoublyLinkedList *list = NULL;

    testCreateNode();
    testInsertBeginning(list);
    testInsertEnd(list);
    testRemove(list);
    
    free(list);
}
