#include <stdlib.h>
#include "doubly_linked_list_queue.h"
#include "../../list/linked-list/doubly-linked-list/doubly_linked_list.h"

DoublyLinkedListQueue *createQueue() {
    DoublyLinkedList *list = createList(NULL, NULL);
    DoublyLinkedListQueue *queue = malloc(sizeof(DoublyLinkedListQueue));
    queue->list = list;
    return queue;
}

void push(int data, DoublyLinkedListQueue *queue) {
    DoublyLinkedNode *node = createNode(data, NULL, NULL);
    insertBeginning(node, queue->list);
}

int pop(DoublyLinkedListQueue *queue) {
    if (queue->list->tail == NULL) {
        return -1;
    }
    int data = queue->list->tail->data;
    removeNode(queue->list->tail, queue->list);
    return data;
}

