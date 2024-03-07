#include <stdlib.h>
#include "binary_tree.h"

int main() {
//    struct List *mylist = (struct List *)calloc(1, sizeof(struct List));
    node *leftChild = malloc(sizeof(node));
    node *rightChild = malloc(sizeof(node));
    node *parent = malloc(sizeof(node));

    leftChild->value = 50;
    rightChild->value = 25;
    parent->value = 100;
    parent->leftChild = leftChild;
    parent -> rightChild = rightChild;

    show(parent);
}
