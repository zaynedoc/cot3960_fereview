#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/algorithms/algos.h"
#include "src/data_structures/linear.h"
#include "src/data_structures/heap.h"
#include "src/data_structures/tree.h"
#include "src/hash/hash.h"

/*
Known bugs:
    - AVL tree delete function has a weird bug when deleting the whole tree
    - Heaps generate a weird big number when extracting/deleting/inserting numbers
    - Hash table function is not implemented yet
*/

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: file not found\n");
        return 1;
    }

    // Read integers into array
    int capacity = 10;
    int size = 0;
    int* array = malloc(capacity * sizeof(int));

    int execution;
    int loopOperation = 1;      // Default to on
    int value;                  // Changed from int* value to int value
    
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        if (size >= capacity) {
            capacity *= 2;
            array = realloc(array, capacity * sizeof(int));
        }
        array[size++] = num;
    }
    fclose(file);

    printf("Original array:\n");
    printArray(array, size);

    printf("\nInput execution code:\n"
       " 1 -> Heap Operations\n"
       " 2 -> AVL Tree Operations\n"
       " 3 -> Basic Sorting (Insertion/Selection/Bubble)\n"
       " 4 -> Advanced Sorting (Merge/Quick)\n"
       " 5 -> Stack Operations\n"
       " 6 -> Queue Operations\n"
       " 7 -> Binary Tree Operations\n"
       " 8 -> Hash Table Operations\n");
    scanf("%d", &execution);

    //Main terminal operations (I don't recommend looking at it):
    switch(execution) {
        case 1:     // Heap function
            printf("\nSelect heap operation:\n 1 -> Min-heap\n 2 -> Max-heap\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid heap operation; terminating program\n");
                return 1;
            } else if (execution == 1) {                 // Min heap operations
                Heap* heap = createHeap(size);
                
                for (int i = 0; i < size; i++) {
                    insert(heap, array[i]);
                }

                printf("\nOriginal array as min heap:\n");
                printHeap(heap);

                while (loopOperation == 1) {
                    printf("\nSelect heap operation:\n 1 -> Extract Min\n 2 -> Insert\n 3 -> Delete Key\n 4 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 4 || execution < 1) {
                        printf("\nInvalid heap operation\n");
                    } else if (execution == 1) {
                        printf("\nExtracting minimum element...\n");
                        printf("Current Heap:\n");
                        printHeap(heap);
                        
                        int min = extractMin(heap);
                        printf("\nExtracted: %d\n", min);
                        
                        printf("\nHeap after extraction:\n");
                        printHeap(heap);
                    } else if (execution == 2) {     
                        printf("\nEnter value to insert: ");
                        scanf("%d", &value);

                        printf("\nCurrent Heap:\n");
                        printHeap(heap);

                        insert(heap, value);

                        printf("\nHeap after insertion:\n");
                        printHeap(heap);
                    } else if (execution == 3) {
                        printf("\nEnter index to delete (0-%d): ", heap->size-1);
                        scanf("%d", &value);

                        if (value >= 0 && value < heap->size) {
                            printf("\nCurrent Heap:\n");
                            printHeap(heap);

                            deleteKey(heap, value);
                            printf("\nHeap after deletion:\n");
                            printHeap(heap);
                        } else {
                            printf("\nInvalid index\n");
                        }
                    } else if (execution == 4) {
                        loopOperation = 0;
                    }
                }
                
                free(heap->heapArray);
                free(heap);
            } else if (execution == 2) {                 // Max heap operations
                Heap* heap = createHeap(size);
                
                for (int i = 0; i < size; i++) {
                    insertMax(heap, array[i]);
                }

                printf("\nOriginal array as max heap:\n");
                printHeap(heap);

                while (loopOperation == 1) {
                    printf("\nSelect heap operation:\n 1 -> Extract Max\n 2 -> Insert\n 3 -> Delete Key\n 4 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 4 || execution < 1) {
                        printf("\nInvalid heap operation\n");
                    } else if (execution == 1) {
                        printf("\nExtracting maximum element...\n");
                        printf("Current Heap:\n");
                        printHeap(heap);
                        
                        int max = extractMax(heap);
                        printf("\nExtracted: %d\n", max);
                        
                        printf("\nHeap after extraction:\n");
                        printHeap(heap);
                    } else if (execution == 2) {     
                        printf("\nEnter value to insert: ");
                        scanf("%d", &value);

                        printf("\nCurrent Heap:\n");
                        printHeap(heap);

                        insertMax(heap, value);

                        printf("\nHeap after insertion:\n");
                        printHeap(heap);
                    } else if (execution == 3) {
                        printf("\nEnter index to delete (0-%d): ", heap->size-1);
                        scanf("%d", &value);

                        if (value >= 0 && value < heap->size) {
                            printf("\nCurrent Heap:\n");
                            printHeap(heap);

                            // For max heap, set to INT_MAX instead of INT_MIN
                            heap->heapArray[value] = INT_MAX;
                            extractMax(heap);

                            printf("\nHeap after deletion:\n");
                            printHeap(heap);
                        } else {
                            printf("\nInvalid index\n");
                        }
                    } else if (execution == 4) {
                        loopOperation = 0;
                    }
                }
                
                free(heap->heapArray);
                free(heap);
            }
            break;
        case 2:     // AVL tree function
            {
                AVLNode* root = NULL;
                int value;
                
                for (int i = 0; i < size; i++) {
                    root = insertAVL(root, array[i]);
                }

                while (loopOperation == 1) {
                    printf("\nArray in AVL Tree Structure:\n");
                    printAVLTree(root);

                    printf("\nInorder Traversal: \n");
                    inorderTraversal(root);

                    printf("\n\nPostorder Traversal: \n");
                    postorderTraversal(root);

                    printf("\n\nPreorder Traversal: \n");
                    preorderTraversal(root);

                    printf("\n\nSelect operation:\n 1 -> Add Node\n 2 -> Delete Node\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid operation; terminating program\n");
                        return 1;
                    } else if (execution == 1) {
                        printf("\nWhich node are you adding? (type existing value): ");
                        scanf("%d", &value);

                        printf("\nAdding %d from tree\nUpdating tree...\n", value);
                        insertAVL(root, value);
                    } else if (execution == 2) {    // Note: attempting to delete the whole tree has a weird bug, I'll try to fix later
                        printf("\nWhich node are you deleting? (type existing value): ");
                        scanf("%d", &value);
                        
                        while (searchAVL(root, value) == NULL) {
                            printf("Value does not exist in tree, try again\n");

                            printf("\nWhich node are you deleting? (type existing value): ");
                            scanf("%d", &value);
                        }

                        printf("\nDeleting %d from tree\nUpdating tree...\n", value);
                        deleteAVLNode(root, value);
                        
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }

                freeAVLTree(root);
            }
            break;
        case 3:     // Basic sorting function
            printf("\nSelect sorting option:\n 1 -> Insertion sort\n 2 -> Selection sort\n 3 -> Bubble sort\n");
            scanf("%d", &execution);

            if (execution > 3 || execution < 1) {
                printf("\nInvalid sorting option; terminating program\n");
                return 1;
            } else if (execution == 1) {
                insertionSort(array, size);
            } else if (execution == 2) {
                selectionSort(array, size);
            } else if (execution == 3) {
                bubbleSort(array, size);
            }
            
            printf("\nUpdated array:\n");
            printArray(array, size);

            break;
        case 4:     // Advanced sorting function
            printf("\nSelect sorting option:\n 1 -> Merge sort\n 2 -> Quick sort\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid sorting option; terminating program\n");
                return 1;
            } else if(execution == 1) {
                mergeSort(array, size);
            } else if(execution == 2) {
                quickSort(array, size);
            }

            printf("\nUpdated array:\n");
            printArray(array, size);
            break;
        case 5:     // Stack function
            printf("\nSelect stack operation:\n 1 -> Array implementation\n 2 -> Linked list implementation\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid stack operation; terminating program\n");
                return 1;
            } else if (execution == 1) {                 // Array stack operations:
                AStack* stack = createAStack(size);

                for (int i = 0; i < size - 1; i++) {        // Last in first out 
                    pushStackA(stack, array[i]);        // First index becomes bottom of stack; vice versa
                }

                printf("\nOriginal array as stack:\n");
                printAStack(stack);

                while (loopOperation == 1) {
                    printf("\nSelect stack operation:\n 1 -> Pop\n 2 -> Push\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid stack operation\n");
                    } else if (execution == 1) {
                        if (emptyStackA(stack)) {
                            printf("\nUnable to pop; stack is empty\n");
                        } else {
                            printf("\nPopping front element...\n");
                            int popped = popStackA(stack);
                            printf("Popped: %d\n", popped);
                            
                            printf("\nCurrent Stack:\n");
                            printAStack(stack);
                        }
                    } else if (execution == 2) {
                        if (fullStackA(stack)) {
                            printf("\nUnable to push; stack is full\n");
                        } else {
                            printf("\nEnter value to push: ");
                            scanf("%d", &value);
                            pushStackA(stack, value);

                            printf("\nCurrent Stack:\n");
                            printAStack(stack);
                        }
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }

                destroyAStack(stack);
            } else if (execution == 2) {                 // Linked list stack operations:
                LStack* stack = createLStack();

                for (int i = 0; i < size; i++) {
                    pushStackL(stack, array[i]);
                }

                printf("\nOriginal array as stack:\n");
                printLStack(stack);

                while (loopOperation == 1) {
                    printf("\nSelect stack operation:\n 1 -> Pop\n 2 -> Push\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid stack operation\n");
                    } else if (execution == 1) {
                        if (emptyStackL(stack)) {
                            printf("\nUnable to pop; stack is empty\n");
                        } else {
                            printf("\nPopping front element...\n");
                            int popped = popStackL(stack);
                            printf("Popped: %d\n", popped);
                            
                            printf("\nCurrent Stack:\n");
                            printLStack(stack);
                        }
                    } else if (execution == 2) {
                        printf("\nEnter value to push: ");
                        scanf("%d", &value);
                        pushStackL(stack, value);

                        printf("\nCurrent Stack:\n");
                        printLStack(stack);
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }

                destroyLStack(stack);
            }
            break;
        case 6:     // Queue function
            printf("\nSelect queue operation:\n 1 -> Array implementation\n 2 -> Linked list implementation\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid queue operation; terminating program\n");
                return 1;
            } else if (execution == 1) {                 // Array queue operations:
                AQueue* queue = createAQueue(size);

                for (int i = 0; i < size; i++) {
                    enqueueA(queue, array[i]);
                }

                printf("\nOriginal array as queue:\n");
                printAQueue(queue);
                
                while (loopOperation == 1) {
                    printf("\nSelect queue operation:\n 1 -> Dequeue\n 2 -> Enqueue\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid queue operation\n");
                    } else if (execution == 1) {
                        if (emptyA(queue)) {
                            printf("\nUnable to dequeue; queue is empty\n");
                        } else {
                            printf("\nDequeuing front element...\n");
                            int removed = dequeueA(queue);
                            printf("Dequeued: %d\n", removed);
                            
                            printf("\nCurrent Queue:\n");
                            printAQueue(queue);
                        }
                    } else if (execution == 2) {
                        if (fullA(queue)) {
                            printf("\nUnable to enqueue; queue is full\n");
                        } else {
                            printf("\nEnter value to enqueue: ");
                            scanf("%d", &value);
                            enqueueA(queue, value);

                            printf("\nCurrent Queue:\n");
                            printAQueue(queue);
                        }
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }
                
                destroyAQueue(queue);
            } else if (execution == 2) {                 // Linked list queue operations:
                LQueue* queue = createLQueue();

                for (int i = 0; i < size; i++) {
                    enqueueL(queue, array[i]);
                }

                printf("\nOriginal array as linked list queue:\n");
                printLQueue(queue);

                while (loopOperation == 1) {
                    printf("\nSelect queue operation:\n 1 -> Dequeue\n 2 -> Enqueue\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid queue operation\n");
                    } else if (execution == 1) {
                        if (emptyL(queue)) {
                            printf("\nUnable to dequeue; queue is empty\n");
                        } else {
                            printf("\nDequeueing front node...\n");
                            int removed = dequeueL(queue);
                            printf("\nDequeued: %d\n", removed);
                            
                            printf("\nCurrent queue:\n");
                            printLQueue(queue);
                        }
                    } else if (execution == 2) {
                        printf("\nEnter value to enqueue: ");
                        scanf("%d", &value);
                        enqueueL(queue, value);
                            
                        printf("\nCurrent Queue:\n");
                        printLQueue(queue);
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }
                
                destroyLQueue(queue);
            }

            break;
        case 7:     // Binary tree function
            printf("\nCreating Binary Search Tree from array...\n");
            TreeNode* root = NULL;
            
            for (int i = 0; i < size; i++) {
                root = insertBST(root, array[i]);
            }
            
            // Print the resulting tree
            printTree(root);

            // Print the sum of the resulting tree
            int sum = treeSum(root);
            printf("\nSum of all nodes: %d\n", sum);
            
            // Clean up
            destroyTree(root);
            break;
        case 8:     // !Hash table function

            break;
        default:
            printf("\nInvalid argument; terminating program\n");
            return 1;
            break;
    }

    printf("\nEnd of program.\n");
    free(array);
    return 0;
}