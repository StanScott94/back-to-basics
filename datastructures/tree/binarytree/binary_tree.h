typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
}node;

typedef struct BinaryTree {
    struct Node *rootNode;
}binaryTree;

void setLeftChild(int value, node *parent);
void setRightChild(int value, node *parent);
void show(node *parent);
