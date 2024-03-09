#include <stdio.h>
#include "binary_tree.h"

int main() {
    int binaryTree[9] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
    node *root = createFromArray(0, binaryTree, sizeof(binaryTree)/sizeof(int));

    show(root);
}
