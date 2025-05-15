typedef struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
} TreeNode;

// BST operations
TreeNode* createNode(int value);
TreeNode* insertBST(TreeNode* root, int value);
void printTreeRecursive(TreeNode* root, int level);
void printTree(TreeNode* root);
void printTabs(int n);
int treeSum(TreeNode* root);
void destroyTree(TreeNode* root);