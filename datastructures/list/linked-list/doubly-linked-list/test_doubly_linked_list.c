#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"

#define VERIFY(s, i) (printf("%s %s", s, (i) ? "successful\n" : "failed\n"))

void testCreateNode() {
    DoublyLinkedNode *node = createDLNode(10, NULL, NULL);
    
    bool expected = node->data == 10 &&
                    node->previous == NULL &&
                    node->next == NULL;
    
    free(node);
    
    VERIFY("testCreateNode", expected);
}

void testInsertBeginning(DoublyLinkedList *list) {
    list = createList(NULL, NULL);
    
    DoublyLinkedNode *nodeA = createDLNode(20, NULL, NULL);
    DoublyLinkedNode *nodeB = createDLNode(10, NULL, NULL);
    
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
    
    DoublyLinkedNode *nodeA = createDLNode(200, NULL, NULL);
    DoublyLinkedNode *nodeB = createDLNode(100, NULL, NULL);
            
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
    
    DoublyLinkedNode *nodeA = createDLNode(200, NULL, NULL);
    DoublyLinkedNode *nodeB = createDLNode(100, NULL, NULL);
            
    insertEnd(nodeA, list);
    insertEnd(nodeB, list);
    removeDLNode(nodeB, list);

    bool expected = list->head->data == 200 &&
        list->head->previous == NULL &&
        list->head->next == NULL &&
        list->tail->data == 200;

    VERIFY("testRemove B", expected);

    insertEnd(nodeB, list);
    removeDLNode(nodeA, list);
        
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
