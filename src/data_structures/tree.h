/*
Runtime Complexities:

Binary Search Tree Operations:
- Insert: O(log n) best/avg, O(n) worst
- Search: O(log n) best/avg, O(n) worst
- Delete: O(log n) best/avg, O(n) worst
- Traversal: O(n) all cases

AVL Tree Operations:
- Insert: O(log n) all cases
- Delete: O(log n) all cases
- Search: O(log n) all cases
- Rotation: O(1) all cases
- Traversal: O(n) all cases
*/

typedef struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
} TreeNode;

TreeNode* createNode(int value);
TreeNode* insertBST(TreeNode* root, int value);
void printTreeRecursive(TreeNode* root, int level);
void printTree(TreeNode* root);
void printTabs(int n);
int treeSum(TreeNode* root);
void destroyTree(TreeNode* root);

typedef struct node {
    int value;
    int height;
    struct node* left;
    struct node* right;
} AVLNode;

AVLNode* createAVLNode(int value);
AVLNode* insertAVL(AVLNode* root, int value);
AVLNode* deleteAVLNode(AVLNode* root, int value);
AVLNode* findInorderSuccessor(AVLNode *node);
AVLNode* searchAVL(AVLNode* , int value);
void inorderTraversal(AVLNode* root);
void postorderTraversal(AVLNode* root);
void preorderTraversal(AVLNode* root);
void freeAVLTree(AVLNode* root);
void printAVLTree(AVLNode* root);
void printAVLTreeRecursive(AVLNode* root, int level);

int getNodeHeight(AVLNode* node);
int maxValue(int a, int b);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* y);
int calculateBalanceFactor(AVLNode* node);