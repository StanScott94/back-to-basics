typedef struct DoublyLinkedNode {
    int data;
    struct DoublyLinkedNode *previous;
    struct DoublyLinkedNode *next;
}DoublyLinkedNode;

typedef struct DoublyLinkedList {
    DoublyLinkedNode *head;
    DoublyLinkedNode *tail;
}DoublyLinkedList;

DoublyLinkedList *createList(DoublyLinkedNode *head,
                             DoublyLinkedNode *tail);

DoublyLinkedNode *createNode(int data,
                             DoublyLinkedNode *previous,
                             DoublyLinkedNode *next);

void insertBefore(DoublyLinkedNode *newNode,
                  DoublyLinkedNode *node, 
                  DoublyLinkedList *list);
                  
void insertBeginning(DoublyLinkedNode *newNode, DoublyLinkedList *list);

void insertAfter(DoublyLinkedNode *newNode,
                 DoublyLinkedNode *node,
                 DoublyLinkedList *list);

void insertEnd(DoublyLinkedNode *newNode, DoublyLinkedList *list);
