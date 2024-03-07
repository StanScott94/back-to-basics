#include <stdio.h>
#include "binary_tree.h"

void setLeftChild(int value, node *parent) {
    node child;
    child.value = value;
    parent->leftChild = &child; 
}

void setRightChild(int value, node *parent) {
    node child;
    child.value = value;
    parent->rightChild = &child;
}

void show(node *parent) {
    printf("Parent: %d, Left: %d, Right: %d\n", parent->value, parent->leftChild->value, parent->rightChild->value);
}
