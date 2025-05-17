#include <stdio.h>
#include <stdlib.h>

// From here to line 97 contains base code for BSTs
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




//From here and on contains base code for AVL trees and operations
typedef struct node {
    int value;
    int height;
    struct node* left;
    struct node* right;
} AVLNode;

// Helper functions relating to height calculations:

// Returns the height of a node, or 0 if node is NULL
int getNodeHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Returns the larger of two numbers
int maxValue(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Balance factor = height of left subtree - height of right subtree
int calculateBalanceFactor(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

// Right rotation is performed when left subtree becomes too tall
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;                                                      
    AVLNode* t2 = x->right;                                                    
    x->right = y;                                                              
    y->left = t2;                                                              

    /* Right Rotation Example: when left subtree becomes too tall (balance > 1)
         Initial:                After Rotation:
             y(+2)                    x(0)
            /   \                    /   \
          x(+1)  c      ==>       a     y(0)
         /   \                          /   \
        a     t2                      t2    c

        Step 1: x = y->left          (x was y's left child)
        Step 2: t2 = x->right        (save x's right subtree)
        Step 3: x->right = y         (y becomes x's right child)
        Step 4: y->left = t2         (t2 becomes y's left child)
    */

    y->height = maxValue(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
    x->height = maxValue(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
    return x;       // Return new root
}

// Left rotation is performed when right subtree becomes too tall
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;                                                     
    AVLNode* t2 = y->left;                                                     
    y->left = x;                                                               
    x->right = t2;                                                             

    /* Left Rotation Example: when right subtree becomes too tall (balance < -1)
         Initial:                After Rotation:
           x(-2)                     y(0)
          /   \                     /   \
         a    y(-1)      ==>     x(0)   c
             /   \              /   \
            t2    c            a    t2

        Step 1: y = x->right         (y was x's right child)
        Step 2: t2 = y->left         (save y's left subtree)
        Step 3: y->left = x          (x becomes y's left child)
        Step 4: x->right = t2        (t2 becomes x's right child)
    */

    x->height = maxValue(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
    y->height = maxValue(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
    return y;   // Return new root
}

AVLNode* findInorderSuccessor(AVLNode* node) {
    AVLNode* current = node;
    
    // Find the leftmost node in the right subtree
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

// Core AVL tree functions:
AVLNode* createAVLNode(int value) {
    AVLNode* node = (AVLNode* )malloc(sizeof(AVLNode));

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* insertAVL(AVLNode* root, int value) {
    if (root == NULL) {                 // Base case: if the AVL tree is empty
        return createAVLNode(value);    // Create the first node
    }                                   // Else, then make a child node

    if (value < root->value) {                           // Is value to insert less than the current root value?
        root->left = insertAVL(root->left, value);      // True: make it the left child of the root
    }  else {
        root->right = insertAVL(root->right, value);    // False: make it the right child of the root
    }

    // AVL tree height calculations:
    root->height = 1 + maxValue(getNodeHeight(root->left), getNodeHeight(root->right));

    // AVL tree balancing calculations:
    int balance = calculateBalanceFactor(root);     //BF of this specific node

    if (balance > 1 && value < root->left->value) {
        return rotateRight(root);
    }

    if (balance > 1 && value > root->left->value) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && value > root->right->value) {
        return rotateLeft(root);
    }

    if (balance < -1 && value < root->right->value) {
        return root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

AVLNode* deleteAVLNode(AVLNode* root, int value) {
    // Base case
    if (root == NULL) {
        return NULL;
    }

    // Standard BST delete
    if (value < root->value) {
        root->left = deleteAVLNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteAVLNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL || root->right == NULL) {
            AVLNode* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else { // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }
            free(temp);
        } else {
            // Node with two children
            AVLNode* temp = findInorderSuccessor(root->right);
            root->value = temp->value;
            root->right = deleteAVLNode(root->right, temp->value);
        }
    }

    // If the tree had only one node then return
    if (root == NULL) {
        return NULL;
    }

    // Update height of current node
    root->height = 1 + maxValue(getNodeHeight(root->left), getNodeHeight(root->right));

    // Get the balance factor of this node to check for unbalance
    int balance = calculateBalanceFactor(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && calculateBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && calculateBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && calculateBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && calculateBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorderTraversal(AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d\t", root->value);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(AVLNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t", root->value);
    }
}

void preorderTraversal(AVLNode* root) {
    if (root != NULL) {
        printf("%d\t", root->value);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void printAVLTreeRecursive(AVLNode* root, int level) {
    if (root == NULL) {
        printTabs(level);
        printf("NULL\n");
        return;
    }
    
    printTabs(level);
    int bf = calculateBalanceFactor(root);
    printf("[%d] (h=%d, bf=%d)\n", root->value, root->height, bf);

    printf("L-> ");
    printAVLTreeRecursive(root->left, level + 1);

    printf("R-> ");
    printAVLTreeRecursive(root->right, level + 1);
}

void printAVLTree(AVLNode* root) {
    printAVLTreeRecursive(root, 0);
}

AVLNode* searchAVL(AVLNode* root, int value) {
    while (root != NULL) {              // Traverse through tree until the root is NULL
        if (root->value > value)
            root = root->left;
        else if (root->value < value)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

void freeAVLTree(AVLNode* root) {
    if (root != NULL) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}