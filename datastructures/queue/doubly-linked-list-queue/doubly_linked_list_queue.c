#include <stdlib.h>
#include "doubly_linked_list_queue.h"
#include "../../list/linked-list/doubly-linked-list/doubly_linked_list.h"

DoublyLinkedListQueue *createQueue() {
    DoublyLinkedList *list = createList(NULL, NULL);
    DoublyLinkedListQueue *queue = malloc(sizeof(DoublyLinkedListQueue));
    queue->list = list;
    return queue;
}

void push(void *data, DoublyLinkedListQueue *queue) {
    DoublyLinkedNode *node = createDLNode(data, NULL, NULL);
    insertBeginning(node, queue->list);
}

void *pop(DoublyLinkedListQueue *queue) {
    if (queue->list->tail == NULL) {
        return NULL;
    }
    void *data = queue->list->tail->data;
    removeDLNode(queue->list->tail, queue->list);
    return data;
}

bool isEmpty(DoublyLinkedListQueue *queue) {
    return queue->list->head == NULL;
}

