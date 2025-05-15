#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/algorithms/algos.h"
#include "src/data_structures/linear.h"
#include "src/data_structures/heap.h"
#include "src/data_structures/tree.h"
#include "src/hash/hash.h"

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
       " 5 -> Linked List Operations\n"
       " 6 -> Stack Operations\n"
       " 7 -> Queue Operations\n"
       " 8 -> Binary Tree Operations\n"
       " 9 -> Hash Table Operations\n");
    scanf("%d", &execution);

    switch(execution) {
        case 1:     //Heapify function
            printf("\nSelect heap operation:\n 1 -> Min-heap\n 2 -> Max-heap\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid heap operation; terminating program.\n");
                return 1;
            } else if (execution == 1) {
                //Min-heap placeholder
            } else if (execution == 2) {
                //Max-heap placeholder
            }
            
            break;
        case 2:     //AVL tree function

            break;
        case 3:     //Basic sorting function
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
        case 4:     //Advanced sorting function
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
        case 5:     //Linked list function
            printf("\nSelect linked list operation:\n 1 -> PLACEHOLDER\n 2 -> PLACEHOLDER\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid linked list operation; terminating program.\n");
                return 1;
            } else if (execution == 1) {
                //
            } else if (execution == 2) {
                //
            }

            break;
        case 6:     //Stack function
            printf("\nSelect queue operation:\n 1 -> Array implementation\n 2 -> Linked list implementation\n");
            scanf("%d", &execution);

            if (execution > 2 || execution < 1) {
                printf("\nInvalid stack operation; terminating program\n");
                return 1;
            } else if (execution == 1) {                 // Array stack operations:
                //createStack

                for (int i = 0; i < size; i++) {
                    //push
                }

                printf("\nOriginal array as stack:\n");
                //printStack

                while (loopOperation == 1) {
                    printf("\nSelect queue operation:\n 1 -> Pop\n 2 -> Push\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid stack operation\n");
                    } else if (execution == 1) {
                        if (true) { //isEmptyA(stack)
                            printf("\nUnable to pop; stack is empty\n");
                        } else {
                            printf("\nPopping front element...\n");
                            //int popped = popped(stack);
                            //printf("Dequeued: %d\n", popped);
                            
                            printf("\nCurrent Stack:\n");
                            //printStack
                        }
                    } else if (execution == 2) {
                        if (true) { //isFullA(stack)
                            printf("\nUnable to push; stack is full\n");
                        } else {
                            printf("\nEnter value to push: ");
                            //scanf("%d", &value);
                            //pushA(stack, value);

                            printf("\nCurrent Stack:\n");
                            //printStack
                        }
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }

                //destroyStack
            } else if (execution == 2) {                 // Linked list stack operations:
                //createStack

                for (int i = 0; i < size; i++) {
                    //push
                }

                printf("\nOriginal array as stack:\n");
                //printStack

                while (loopOperation == 1) {
                    printf("\nSelect queue operation:\n 1 -> Pop\n 2 -> Push\n 3 -> End\n");
                    scanf("%d", &execution);

                    if (execution > 3 || execution < 1) {
                        printf("\nInvalid stack operation\n");
                    } else if (execution == 1) {
                        if (true) { //isEmptyL(stack)
                            printf("\nUnable to pop; stack is empty\n");
                        } else {
                            printf("\nPopping front element...\n");
                            //int popped = popped(stack);
                            //printf("Dequeued: %d\n", popped);
                            
                            printf("\nCurrent Stack:\n");
                            //printStack
                        }
                    } else if (execution == 2) {
                        printf("\nEnter value to push: ");
                        //scanf("%d", &value);
                        //pushA(stack, value);

                        printf("\nCurrent Stack:\n");
                        //printStack
                    } else if (execution == 3) {
                        loopOperation = 0;
                    }
                }

                //destroyStack
            }
            break;
        case 7:     //Queue function
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
        case 8:     //Binary tree function

            break;
        case 9:     //Hash table function

            break;
        default:
            printf("\nInvalid argument; terminating program.\n");
            return 1;
            break;
    }

    printf("\nEnd of program.\n");
    free(array);
    return 0;
}