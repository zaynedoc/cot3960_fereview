#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int capacity;   // Maximum size of heap
    int size;       // Current number of elements
    int* heapArray; // Array to store heap elements
} Heap;

void swapHeaps(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->heapArray = (int*)malloc(capacity * sizeof(int));
    return heap;
}

void heapify(Heap* heap, int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // Find smallest among root, left child and right child
    if (left < n && heap->heapArray[left] < heap->heapArray[smallest])
        smallest = left;

    if (right < n && heap->heapArray[right] < heap->heapArray[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swapHeaps(&heap->heapArray[i], &heap->heapArray[smallest]);
        heapify(heap, smallest, n); // Recursively heapify the affected sub-tree
    }
}

void maxHeapify(Heap* heap, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap->heapArray[left] > heap->heapArray[largest])
        largest = left;

    if (right < n && heap->heapArray[right] > heap->heapArray[largest])
        largest = right;

    if (largest != i) {
        swapHeaps(&heap->heapArray[i], &heap->heapArray[largest]);
        maxHeapify(heap, largest, n);
    }
}

void insert(Heap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }

    // Insert new key at the end
    int i = heap->size++;
    heap->heapArray[i] = key;

    // Fix the min heap property if it is violated
    while (i != 0 && heap->heapArray[(i - 1) / 2] > heap->heapArray[i]) {
        swapHeaps(&heap->heapArray[i], &heap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertMax(Heap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }

    int i = heap->size++;
    heap->heapArray[i] = key;

    while (i != 0 && heap->heapArray[(i - 1) / 2] < heap->heapArray[i]) {
        swapHeaps(&heap->heapArray[i], &heap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int getMin(Heap* heap) {
    if (heap->size <= 0) return INT_MAX;
    return heap->heapArray[0];
}

int getMax(Heap* heap) {
    if (heap->size <= 0) return INT_MIN;
    return heap->heapArray[0];
}

int extractMin(Heap* heap) {
    if (heap->size <= 0) return INT_MAX;
    if (heap->size == 1) {
        heap->size--;
        return heap->heapArray[0];
    }

    // Store the minimum value and remove it from heap
    int root = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[--heap->size];
    heapify(heap, 0, heap->size);

    return root;
}

int extractMax(Heap* heap) {
    if (heap->size <= 0) return INT_MIN;
    if (heap->size == 1) {
        heap->size--;
        return heap->heapArray[0];
    }

    int root = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[--heap->size];
    maxHeapify(heap, 0, heap->size);

    return root;
}

void decreaseKey(Heap* heap, int i, int new_val) {
    heap->heapArray[i] = new_val;
    while (i != 0 && heap->heapArray[(i - 1) / 2] > heap->heapArray[i]) {
        swapHeaps(&heap->heapArray[i], &heap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteKey(Heap* heap, int i) {
    decreaseKey(heap, i, INT_MIN);  // Make it the smallest possible value
    extractMin(heap);               // Remove it from the heap
}

void buildMinHeap(Heap* heap) {
    // Start from last non-leaf node and heapify all nodes in reverse order
    for (int i = heap->size / 2 - 1; i >= 0; i--)
        heapify(heap, i, heap->size);
}

void buildMaxHeap(Heap* heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--)
        maxHeapify(heap, i, heap->size);
}

void heapSort(Heap* heap) {
    buildMinHeap(heap);
    int originalSize = heap->size;

    // Extract elements from heap one by one
    for (int i = heap->size - 1; i >= 0; i--) {
        swapHeaps(&heap->heapArray[0], &heap->heapArray[i]);
        heapify(heap, 0, i);
    }

    // Reverse array to get ascending order
    for (int i = 0; i < originalSize/2; i++) {
        swapHeaps(&heap->heapArray[i], &heap->heapArray[originalSize - 1 - i]);
    }
}

// Helper function for printHeap to calculate the height of heap
int getHeapHeight(Heap* heap) {
    int height = 0;
    int size = heap->size;
    while (size > 0) {
        height++;
        size = size / 2;
    }
    return height;
}

void printHeap(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return;
    }

    int height = getHeapHeight(heap);
    int maxWidth = (1 << height) * 2;  // 2^height * 2 for spacing

    printf("\nHeap Structure:\n\n");

    // Print heap as a tree
    int level = 0;
    int levelNodes = 1;
    int index = 0;

    while (index < heap->size) {
        // Calculate padding for this level
        int padding = (maxWidth / (levelNodes * 2));

        // Print leading spaces for this level
        for (int i = 0; i < padding; i++) printf(" ");

        // Print nodes at this level
        for (int i = 0; i < levelNodes && index < heap->size; i++) {
            printf("%2d", heap->heapArray[index++]);
            for (int j = 0; j < padding * 2; j++) printf(" ");
        }
        printf("\n\n");  // Extra newline for better visibility

        level++;
        levelNodes *= 2;
    }
    printf("\n");
}