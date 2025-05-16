/*
Runtime Complexities:

Min/Max Heap Operations:
- Insert: O(log n) all cases
- Extract Min/Max: O(log n) all cases
- Get Min/Max: O(1) all cases
- Decrease Key: O(log n) all cases
- Delete: O(log n) all cases
- Build Heap: O(n) all cases
- Heapify: O(log n) all cases
- Heap Sort: O(n log n) all cases
*/

#include <limits.h>

typedef struct {
    int capacity;
    int size;
    int* heapArray;
} Heap;

// Core heap operations
Heap* createHeap(int capacity);
void insert(Heap* heap, int key);
int getMin(Heap* heap);
int extractMin(Heap* heap);
void decreaseKey(Heap* heap, int i, int new_val);
void deleteKey(Heap* heap, int i);

// Heap maintenance operations
void heapify(Heap* heap, int i, int n);
void buildMinHeap(Heap* heap);
void heapSort(Heap* heap);

// Max heap operations
void maxHeapify(Heap* heap, int i, int n);
void insertMax(Heap* heap, int key);
int getMax(Heap* heap);
int extractMax(Heap* heap);
void buildMaxHeap(Heap* heap);

// Utility functions
void swapHeaps(int* a, int* b);
void printHeap(Heap* heap);