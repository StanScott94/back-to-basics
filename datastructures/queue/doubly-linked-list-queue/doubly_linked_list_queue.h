typedef struct DoublyLinkedListQueue {
    struct DoublyLinkedList *list;
}DoublyLinkedListQueue;

DoublyLinkedListQueue *createQueue();
void push(int data, DoublyLinkedListQueue *queue);
int pop(DoublyLinkedListQueue *queue);
