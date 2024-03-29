#include <stdio.h>
#include <stdbool.h>
#include "doubly_linked_list_queue.h"

#define VERIFY(s, i) (printf("%s %s", s, (i) ? "successful\n" : "failed\n"))

int main() {
    DoublyLinkedListQueue *queue = createQueue();
    push(10, queue);
    push(20, queue);
    push(30, queue);
    
    bool expected = false;
    
    expected = pop(queue) == 10 &&
               pop(queue) == 20 &&
               pop(queue) == 30 &&
               isEmpty(queue);
    
    VERIFY("DoublyLinkedListQueue", expected);
}

