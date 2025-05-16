#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a heap
typedef struct {
    int capacity;
    int size;
    int* heapArray;
} heap_t;

// Swap utility function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Initialize a heap with a given capacity
heap_t* initializeHeapWithSize(int capacity) {
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->capacity = capacity;
    heap->size = 0;
    heap->heapArray = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Heapify function to restore the heap property from index i down
// heapify ensures that the subtree rooted at index `i` maintains the min-heap property
// If the node at index i is greater than one of its children, we swap it with the smallest child
// and continue heapifying recursively down the tree.
void heapify(heap_t* heap, int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap->heapArray[left] < heap->heapArray[smallest])
        smallest = left;

    if (right < n && heap->heapArray[right] < heap->heapArray[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap->heapArray[i];
        heap->heapArray[i] = heap->heapArray[smallest];
        heap->heapArray[smallest] = temp;
        heapify(heap, smallest, n);
    }
}

// insert() adds a new key into the min-heap
// It places the new value at the end of the heap array,
// then "bubbles it up" by swapping it with its parent until the min-heap property is restored

void insert(heap_t* heap, int key) {
    // Check if heap is already full
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new key at the end of the heap
    int i = heap->size++;
    heap->heapArray[i] = key;

    // Bubble-up step:
    // While the inserted node is smaller than its parent, keep swapping
    while (i != 0 && heap->heapArray[(i - 1) / 2] > heap->heapArray[i]) {
        // Swap with parent
        swap(&heap->heapArray[i], &heap->heapArray[(i - 1) / 2]);

        // Move up to parent index
        i = (i - 1) / 2;
    }
}

// Get the minimum element (root)
int getMin(heap_t* heap) {
    if (heap->size <= 0) return INT_MAX;
    return heap->heapArray[0];
}

// Extract and remove the minimum element (root)
int extractMin(heap_t* heap) {
    if (heap->size <= 0) return INT_MAX;
    if (heap->size == 1) return heap->heapArray[--heap->size];

    int root = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[--heap->size];
    heapify(heap, 0, heap->size);

    return root;
}

// Decrease value of a key at index i to new_val
void decreaseKey(heap_t* heap, int i, int new_val) {
    heap->heapArray[i] = new_val;
    while (i != 0 && heap->heapArray[(i - 1) / 2] > heap->heapArray[i]) {
        swap(&heap->heapArray[i], &heap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete a key at a given index
void delete(heap_t* heap, int i) {
    decreaseKey(heap, i, INT_MIN); // Set to smallest possible
    extractMin(heap);              // Remove it
}

// Print the contents of the heap
void printHeap(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Build a min-heap from array
void buildMinHeap(heap_t* heap) {
    // Start at the middle index
    for (int i = heap->size / 2 - 1; i >= 0; --i)
        heapify(heap, i, heap->size);
}

// Heap sort function using the min-heap
void heapSort(heap_t* heap) {
    buildMinHeap(heap);

    int originalSize = heap->size;

    for (int i = heap->size - 1; i >= 0; --i) {
        // Move current smallest to end
        swap(&heap->heapArray[0], &heap->heapArray[i]);
        // Heapify reduced heap without modifying heap->size
        heapify(heap, 0, i);
    }

    // Reverse array to get ascending order
    int start = 0, end = originalSize - 1;
    while (start < end) {
        int temp = heap->heapArray[start];
        heap->heapArray[start] = heap->heapArray[end];
        heap->heapArray[end] = temp;
        start++;
        end--;
    }
}

// Main function with updated test case
int main() {
    heap_t* minHeap = initializeHeapWithSize(15);

    // Insert values into the heap
    insert(minHeap, 42);
    insert(minHeap, 29);
    insert(minHeap, 18);
    insert(minHeap, 14);
    insert(minHeap, 7);
    insert(minHeap, 18);
    insert(minHeap, 12);
    insert(minHeap, 11);

    // Perform delete at index 3
    delete(minHeap, 3);

    // Extract minimum and print
    printf("extractMin() = %d\n", extractMin(minHeap));

    // Get and print current min
    printf("getMin() = %d\n", getMin(minHeap));

    // Decrease key at index 2 to 1
    decreaseKey(minHeap, 2, 1);
    printf("getMin() after decreaseKey = %d\n", getMin(minHeap));

    // Print heap before sorting
    printf("Heap contents before sorting:\n");
    printHeap(minHeap->heapArray, minHeap->size);

    // Sort the heap
    heapSort(minHeap);

    // Print sorted result
    printf("Sorted heap contents:\n");
    printHeap(minHeap->heapArray, minHeap->size);

    return 0;
}
