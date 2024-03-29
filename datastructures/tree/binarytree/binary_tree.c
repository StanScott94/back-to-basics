#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include "../../queue/doubly-linked-list-queue/doubly_linked_list_queue.h"

#define LEFT_POSITION(i) ((i*2)+1)
#define RIGHT_POSITION(i) ((i*2)+2)

static node *_removeBTNode(int value, node **currentNode);
static node *_createFromArray(int positionInTree, int *tree, int treeSize);

node *removeBTNode(int value, node *currentNode) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (currentNode->value == value) {
        printf("Cannot delete root node\n");
        return NULL;
    }

    node *nodeToRemove = _removeBTNode(value, &currentNode->leftChild);
    if (nodeToRemove != NULL) {
        return nodeToRemove;
    }

    nodeToRemove = _removeBTNode(value, &currentNode->rightChild);
    if (nodeToRemove != NULL) {
        return nodeToRemove;
    }

    return NULL;
}

static node *_removeBTNode(int value, node **currentNode) {
    if (*currentNode != NULL) {
        if ((*currentNode)->value == value) {
            if ((*currentNode)->leftChild != NULL
                && (*currentNode)->rightChild != NULL) {
                printf("Cannot delete parent node with two children\n");
                return NULL;
            } else {
                node *nodeToRemove = *currentNode;
                if ((*currentNode)->leftChild != NULL) {
                   *currentNode = (*currentNode)->leftChild;
                } else if ((*currentNode)->rightChild != NULL) {
                    *currentNode = (*currentNode)->rightChild;
                } else {
                    *currentNode = NULL;
                }
                return nodeToRemove;
            }
        } else {
            node *nodeToRemove = removeBTNode(value, *currentNode);
            if (nodeToRemove != NULL) {
                return nodeToRemove;
            }
        }
    }
    return NULL;
}

node *findBTNode(int value, node *currentNode) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (currentNode->value == value) {
        return currentNode;
    }

    node *nodeToFind = findBTNode(value, currentNode->leftChild);
    if (nodeToFind != NULL) {
        return nodeToFind;
    }
 
    nodeToFind = findBTNode(value, currentNode->rightChild);
    if (nodeToFind != NULL) {
        return nodeToFind;
    }
 
    return NULL;
}

node *createFromArray(int *tree, int treeSize) {
    return _createFromArray(0, tree, treeSize);
}

static node *_createFromArray(int positionInTree, int *tree, int treeSize) {
    if (positionInTree >= treeSize || tree[positionInTree] == -1) {
       return NULL;
    }

    node *newNode = createBTNode(tree[positionInTree], NULL, NULL);

    if (LEFT_POSITION(positionInTree) < treeSize) {
        node *leftChild = _createFromArray(LEFT_POSITION(positionInTree), tree, treeSize);
        insertLeftChild(newNode, leftChild);
    }

    if (RIGHT_POSITION(positionInTree) < treeSize) {
        node *rightChild = _createFromArray(RIGHT_POSITION(positionInTree), tree, treeSize);
        insertRightChild(newNode, rightChild);
    }

//    show(newNode);
    return newNode;
}

int *writeToArray(node *root, int *arraySize) {

    DoublyLinkedListQueue *queue = createQueue();
        push(root, queue);
        
        node *currentNode;
        int index = 0;
        int capacity = 1;
        int *storedBinaryTree = (int *)malloc(capacity * sizeof(int));
     
        while (!isEmpty(queue)) {
            currentNode = pop(queue);
            if (index == capacity) {
                capacity *= 2;
                int *temp = (int *)realloc(storedBinaryTree, capacity * sizeof(int));
                if (temp == NULL) {
                    free(storedBinaryTree);
                    return NULL;
                }
                storedBinaryTree = temp;
            }
            storedBinaryTree[index++] = currentNode->value;
            if(currentNode->leftChild != NULL) {
                push(currentNode->leftChild, queue);
            }
            if(currentNode->rightChild != NULL) {
                push(currentNode->rightChild, queue);
            }
        }
    *arraySize = index;
    return storedBinaryTree;
}

node *createBTNode(int value, node *leftChild, node *rightChild) {
    node *parent = malloc(sizeof(node));
    parent->value = value;
    parent->leftChild = leftChild;
    parent->rightChild = rightChild;
    return parent;
}

void insertLeftChild(node *parent, node *child) {
    if (parent->leftChild != NULL) {
        child->leftChild = parent->leftChild;
    }
    parent->leftChild = child;
}

void insertRightChild(node *parent, node *child) {
    if (parent->rightChild != NULL) {
        child->leftChild = parent->rightChild;
    }
    parent->rightChild = child;
}

void show(node *parent) {
    int value = parent->value;
    int leftVal = parent->leftChild != NULL ? parent->leftChild->value : -1;
    int rightVal = parent->rightChild != NULL ? parent->rightChild->value : -1;
    printf("Parent: %d, Left: %d, Right: %d\n", value, leftVal, rightVal);
}
