typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
}node;

typedef struct BinaryTree {
    struct Node *rootNode;
}binaryTree;

node *createFromArray(int positionInTree, int tree[], int treeSize);
node *createNode(int value, node *leftChild, node *rightChild);
void insertLeftChild(node *parent, node *child);
void insertRightChild(node *parent, node *child);
void show(node *parent);
