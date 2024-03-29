#include <stdbool.h>
#include <stdio.h>
#include "binary_tree.h"

#define VERIFY(s, i) (printf("%s %s", s, (i) ? "successful\n" : "failed\n"))

void testFindNode() {
    int binaryTree[] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    node *root = createFromArray(binaryTree, sizeof(binaryTree)/sizeof(binaryTree[0]));
    
    node *nodeFound1 = findBTNode(19, root);
    node *nodeFound2 = findBTNode(36, root);
    
    VERIFY("testFindNode", nodeFound1->leftChild->value == 17 &&
                           nodeFound1->rightChild->value == 3 &&
                           nodeFound2->leftChild->value == 25 &&
                           nodeFound2->rightChild->value == 1);
}

void testInsertChild() {
    node *parentNode = createBTNode(100, NULL, NULL);
    node *leftChild = createBTNode(50, NULL, NULL);
    node *rightChild = createBTNode(25, NULL, NULL);
    
    insertLeftChild(parentNode, leftChild);
    insertRightChild(parentNode, rightChild);
    
    VERIFY("testInsertChild", parentNode->leftChild->value == 50 &&
                              parentNode->rightChild->value == 25);
}

void testWriteToArray() {
    int binaryTree[] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    node *root = createFromArray(binaryTree, sizeof(binaryTree)/sizeof(binaryTree[0]));
    
    int resultSize = 0;
    int *result = writeToArray(root, &resultSize);
    
    bool treesEqual = true;
    
    for(size_t i = 0; i < sizeof(binaryTree) / sizeof(int); i++) {
        if (binaryTree[i] != result[i]) {
            treesEqual = false;
            break;
        }
    }

    VERIFY("testWriteToArray", sizeof(binaryTree) / sizeof(int) == resultSize && treesEqual);
}

int main() {
    testFindNode();
    testInsertChild();
    testWriteToArray();
}
