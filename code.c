#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    union {
        int num;
        char* str;
    } data;
    struct Node* next;
} Node;

typedef struct {
    void* array;  // Will be either int* or char**
    int size;
    int isString; // 0 for integers, 1 for strings
} DataContainer;

DataContainer* readInput(FILE* file);
void printData(DataContainer* dc);

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

    DataContainer* data = readInput(file);
    fclose(file);

    int execution;
    printf("Original input:\n");
    printData(data);

    printf("\nInput execution code:\n"
       "1 -> Heap Operations (Min/Max Heap)\n"
       "2 -> AVL Tree Operations\n"
       "3 -> Basic Sorting (Insertion/Selection/Bubble)\n"
       "4 -> Advanced Sorting (Merge/Quick)\n"
       "5 -> Linked List Operations\n"
       "6 -> Stack Operations\n"
       "7 -> Queue Operations\n"
       "8 -> Binary Tree Operations\n"
       "9 -> Hash Table Operations\n");
    scanf("%d", &execution);

    switch(execution) {
        //Heapify function
        case 1:
            printf("\nSelect heapify option:\n 1 -> Min-heap\n 2 -> Max-heap\n");
            scanf("%d", &execution);

            if(execution == 1)
                //Min-heap placeholder
            if(execution == 2)
                //Max-heap placeholder
            if(execution != 1 && execution != 2)
                printf("Invalid heapify option; terminating program.\n");

            break;
        
        //AVL tree function
        case 2:

            break;

        //Basic sorting function
        case 3:

            break;

        //Advanced sorting function
        case 4:

            break;

        //Linked list function
        case 5:

            break;

        //Stack function
        case 6:

            break;

        //Queue function
        case 7:

            break;
        default:
            printf("Invalid argument; terminating program.\n");
            break;
    }

    fclose(file);

    return 0;
}

/* Code Expected Input & Output:

1. Read input file upon file execution
2. Denote wether input file is composed of only digits or only strings
3. List sorting algorithms with associated "execution codes"

    "1 -> Heap sort
    2 -> AVL tree sort
    3 -> Merge sort
    4 -> Quick sort
    ..."

4. Sort alogirmth based on execution code
5. Example output:

    "Your original input:
    [6, 3, 7, 8, 2, 4]

    Sorted list using {algorithm}:
    [2, 3, 4, 6, 7, 8]"


    Other notes:
    - File I/O in only read mode (all operations conducted in terminal)
    - Utilize memory allocation to fullest extent
*/

// Function to read and determine input type
DataContainer* readInput(FILE* file) {
    DataContainer* dc = malloc(sizeof(DataContainer));
    char buffer[100];
    int isString = 0;
    int capacity = 10;
    int count = 0;
    
    // Read first value to determine type
    if (fscanf(file, "%s", buffer) == 1) {
        isString = (strspn(buffer, "0123456789-") != strlen(buffer));
    }
    
    dc->isString = isString;
    rewind(file);
    
    if (isString) {
        dc->array = malloc(capacity * sizeof(char*));
    } else {
        dc->array = malloc(capacity * sizeof(int));
    }
    
    while (fscanf(file, "%s", buffer) == 1) {
        if (count >= capacity) {
            capacity *= 2;
            if (isString) {
                dc->array = realloc(dc->array, capacity * sizeof(char*));
            } else {
                dc->array = realloc(dc->array, capacity * sizeof(int));
            }
        }
        
        if (isString) {
            ((char**)dc->array)[count] = strdup(buffer);
        } else {
            ((int*)dc->array)[count] = atoi(buffer);
        }
        count++;
    }
    
    dc->size = count;
    return dc;
}

// Function to print the DataContainer
void printData(DataContainer* dc) {
    if (!dc) return;
    
    printf("[");
    for (int i = 0; i < dc->size; i++) {
        if (dc->isString) {
            printf("%s", ((char**)dc->array)[i]);
        } else {
            printf("%d", ((int*)dc->array)[i]);
        }
        if (i < dc->size - 1) printf(", ");
    }
    printf("]\n");
}