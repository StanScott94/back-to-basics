#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

#define LEFT_POSITION(i) ((i*2)+1)
#define RIGHT_POSITION(i) ((i*2)+2)

node *createFromArray(int positionInTree, int tree[], int treeSize) {
    if (positionInTree >= treeSize || tree[positionInTree] == -1) {
       return NULL;
    }

    node *newNode = createNode(tree[positionInTree], NULL, NULL);

    if (LEFT_POSITION(positionInTree) < treeSize) {
        node *leftChild = createFromArray(LEFT_POSITION(positionInTree), tree, treeSize);
        insertLeftChild(newNode, leftChild);
    }

    if (RIGHT_POSITION(positionInTree) < treeSize) {
        node *rightChild = createFromArray(RIGHT_POSITION(positionInTree), tree, treeSize);
        insertRightChild(newNode, rightChild);
    }

    show(newNode);
    return newNode;
}

node *createNode(int value, node *leftChild, node *rightChild) {
    node *parent = malloc(sizeof(node));
    parent->value = value;
    parent->leftChild = leftChild;
    parent->rightChild = rightChild;
    return parent;
}

void insertLeftChild(node *parent, node *child) {
    node *currentChild = parent->leftChild;
    parent->leftChild = child;
    if (child != NULL) {
        child->leftChild = currentChild;
    }
}

void insertRightChild(node *parent, node *child) {
    node *currentChild = parent->rightChild;
    parent->rightChild = child;
    if (child != NULL) {
        child->leftChild = currentChild;
    }
}

void show(node *parent) {
    int value = parent->value;
    int leftVal = parent->leftChild != NULL ? parent->leftChild->value : -1;
    int rightVal = parent->rightChild != NULL ? parent->rightChild->value : -1;
    printf("Parent: %d, Left: %d, Right: %d\n", value, leftVal, rightVal);
}
