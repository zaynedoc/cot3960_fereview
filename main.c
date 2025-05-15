#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

            if(execution > 2 || execution < 1) {
                printf("\nInvalid heap operation; terminating program.\n");
                return 1;
            } else if(execution == 1) {
                //Min-heap placeholder
            } else if(execution == 2) {
                //Max-heap placeholder
            }
            
            break;
        case 2:     //AVL tree function

            break;
        case 3:     //Basic sorting function
            printf("\nSelect sorting option:\n 1 -> Insertion sort\n 2 -> Selection sort\n 3 -> Bubble sort\n");
            scanf("%d", &execution);

            if(execution > 3 || execution < 1) {
                printf("\nInvalid sorting option; terminating program.\n");
                return 1;
            } else if(execution == 1) {
                insertionSort(array, size);
            } else if(execution == 2) {
                selectionSort(array, size);
            } else if(execution == 3) {
                bubbleSort(array, size);
            }
            
            printf("\nUpdated array:\n");
            printArray(array, size);

            break;
        case 4:     //Advanced sorting function
            printf("\nSelect sorting option:\n 1 -> Merge sort\n 2 -> Quick sort\n");
            scanf("%d", &execution);

            if(execution > 2 || execution < 1) {
                printf("\nInvalid sorting option; terminating program.\n");
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
            printf("\nSelect linked list operation:\n 1 -> Min-heap\n 2 -> Max-heap\n");
            scanf("%d", &execution);

            if(execution > 2 || execution < 1) {
                printf("\nInvalid linked list operation; terminating program.\n");
                return 1;
            } else if(execution == 1) {
                //Min-heap placeholder
            } else if(execution == 2) {
                //Max-heap placeholder
            }

            break;
        case 6:     //Stack function

            break;
        case 7:     //Queue function

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