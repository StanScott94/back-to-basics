#include <stdio.h>
#include "binary_tree.h"

node *_removeNode(int value, node *currentNode) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (currentNode->value == value) {
        printf("Cannot delete root node\n");
        return NULL;
    }

    node *nodeToRemove;

    if (currentNode->leftChild != NULL) {
        if (currentNode->leftChild->value == value) {
            if (currentNode->leftChild->leftChild != NULL
                && currentNode->leftChild->rightChild != NULL) {
                printf("Cannot delete parent node with two children\n");
                return NULL;
            } else {
                if (currentNode->leftChild->leftChild != NULL) {
                    nodeToRemove = currentNode->leftChild;
                    currentNode->leftChild = currentNode->leftChild->leftChild;
                } else if (currentNode->leftChild->rightChild != NULL) {
                    nodeToRemove = currentNode->leftChild;
                    currentNode->leftChild = currentNode->leftChild->rightChild;
                } else {
                    currentNode->leftChild = NULL;
                    return nodeToRemove;
                }
            }
        } else {
            nodeToRemove = removeNode(value, currentNode->leftChild);
            if (nodeToRemove != NULL) {
                return nodeToRemove;
            }
        }
    }

    return NULL;
}

node *removeNode(int value, node *currentNode) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (currentNode->value == value) {
        printf("Cannot delete root node\n");
        return NULL;
    }

    node *nodeToRemove;

    if (currentNode->leftChild != NULL) {
        if (currentNode->leftChild->value == value) {
            if (currentNode->leftChild->leftChild != NULL 
                && currentNode->leftChild->rightChild != NULL) {
                printf("Cannot delete parent node with two children\n");
                return NULL;
            } else {
                if (currentNode->leftChild->leftChild != NULL) {
                    nodeToRemove = currentNode->leftChild;
                    currentNode->leftChild = currentNode->leftChild->leftChild;
                } else if (currentNode->leftChild->rightChild != NULL) {
                    nodeToRemove = currentNode->leftChild;
                    currentNode->leftChild = currentNode->leftChild->rightChild;
                } else {
                    currentNode->leftChild = NULL;
                    return nodeToRemove;
                }
            }
        } else {
            nodeToRemove = removeNode(value, currentNode->leftChild);
            if (nodeToRemove != NULL) {
                return nodeToRemove;
            }
        }
    }

    return NULL;
}

int main() {
    int binaryTree[9] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    node *root = createFromArray(0, binaryTree, sizeof(binaryTree)/sizeof(int));

    node *nodeFound = findNode(19, root);

    node *newNode = createNode(50, NULL, NULL);

    insertLeftChild(nodeFound, newNode);

printf("=========\n");
    removeNode(50, root);
    show(findNode(19, root));
    removeNode(2, root);
    removeNode(7, root);
    show(findNode(17, root));
    removeNode(25, root);
    show(findNode(36, root));
    removeNode(36, root);
    show(findNode(100, root));
}
