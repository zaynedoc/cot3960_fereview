#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (node != NULL) {
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

TreeNode* insertBST(TreeNode* root, int value) {
    if (root == NULL) {                             // If tree is empty, create the first node; root
        return createNode(value);
    }
    
    if (value < root->value) {                      // If value is less than current node, go left
        root->left = insertBST(root->left, value);
    }
    else if (value > root->value) {                 // If value is greater than current node, go right
        root->right = insertBST(root->right, value);
    }
    
    return root;
}

void printTabs(int n) {
    for (int i = 0; i < n; i++) {
        printf("\t");
    }
}

void printTreeRecursive(TreeNode* root, int level) {
    if (root == NULL) {
        printTabs(level);
        printf("NULL\n");
        return;
    }
    
    printTabs(level);
    printf("[%d]\n", root->value);

    printf("L-> ");
    printTreeRecursive(root->left, level + 1);

    printf("R-> ");
    printTreeRecursive(root->right, level + 1);

    /* Example output of array [5,3,7,1,4,6,8]:

    level:   0   1   2   3
            [5]
                [3]
                    [1]
                        NULL
                        NULL
                    [4]
                        NULL
                        NULL
                [7]
                    [6]
                        NULL
                        NULL
                    [8]
                        NULL
                        NULL
    */
}

void printTree(TreeNode* root) {
    printf("\nBinary Search Tree Structure:\n");
    printTreeRecursive(root, 0);
}

int treeSum(TreeNode* root) {       // Recrusively, because they LOVE recursion on this exam :)
    if (root == NULL) {             // Base case
        return 0;                   // If there is no left/right child of root, add 0 to recursive equation
    }
    return root->value + treeSum(root->left) + treeSum(root->right);    // Recall function while continuously adding previous values until all nodes of tree are added
}

void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}