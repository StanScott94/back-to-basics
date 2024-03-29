#include <stdio.h>
#include "binary_tree.h"

int *writeToArray(node *root) {
   //TODO first implement LinkedList data structure
}

int main() {
    int binaryTree[9] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    node *root = createFromArray(binaryTree, sizeof(binaryTree)/sizeof(binaryTree[0]));

    node *nodeFound = findNode(19, root);
    node *newNode = createNode(50, NULL, NULL);
    insertLeftChild(nodeFound, newNode);

    show(removeNode(50, root));
    printf("---\n");    
    signed int *newBinaryTree = writeToArray(root);
    
//    for (int i = 0; i <= sizeof(newBinaryTree)/sizeof(newBinaryTree[0]); i++) {
    for (int i = 0; i <= 8; i++) {
        printf("%d ", newBinaryTree[i]);
    }
    printf("\n");
}
