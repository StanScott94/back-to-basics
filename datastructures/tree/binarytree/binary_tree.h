typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
}node;

typedef struct BinaryTree {
    struct Node *rootNode;
}binaryTree;

node *removeBTNode(int value, node *currentNode);
node *findBTNode(int value, node *currentNode);
node *createFromArray(int *tree, int treeSize);
node *createBTNode(int value, node *leftChild, node *rightChild);
int *writeToArray(node *root, int *arraySize);
void insertLeftChild(node *parent, node *child);
void insertRightChild(node *parent, node *child);
void show(node *parent);
