#include <stdbool.h>

typedef struct DoublyLinkedListQueue {
    struct DoublyLinkedList *list;
}DoublyLinkedListQueue;

DoublyLinkedListQueue *createQueue();
void push(void *data, DoublyLinkedListQueue *queue);
void *pop(DoublyLinkedListQueue *queue);
bool isEmpty(DoublyLinkedListQueue *queue);
