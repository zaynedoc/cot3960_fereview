#include <stdio.h>

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Iterate through the array and pick each element one by one
// Compare the picked element with the elements in the sorted part of the array
// Shift the elements in the sorted part to make space for the picked element
// Insert the picked element at the correct position
// Time Complexity: O(n^2) in the worst case, O(n) in the best case
void insertionSort(int* arr, int n) {
    printf("\nInsertion Sort Algorithm...\n");
    printArray(arr, n);                         // Print the initial array
    
    for (int i = 1; i < n; i ++) {
        int key = arr[i];                       // Current element to be inserted
        int j = i - 1;                          // Index of the last sorted element

        while (j >= 0 && arr[j] > key) {        // As long as the current element is smaller than the last sorted element
            arr[j + 1] = arr[j];                // Shift elements
            j = j - 1;                          // Iterate to the next element
        }

        arr[j + 1] = key;                       // Insert the current element at the correct position 
        
        printArray(arr, n);                     // Print the array after each insertion
    }
}

// Iterate through the array and find the minimum element in the unsorted part of the array
// Swap the found minimum element with the first element of the unsorted part
// Repeat the process for the next element
// Time Complexity: O(n^2) in the worst case, O(n) in the best case
void selectionSort(int* arr, int n) {
    printf("\nSelection Sort Algorithm...\n");
    printArray(arr, n);

    for (int i = 0; i < n - 1; i ++) {
        int minIndex = i;                       // Index of the minimum element
        for (int j = i + 1; j < n; j ++) {      // Iterate through the unsorted part of the array
            if (arr[j] < arr[minIndex]) {       // If a smaller element is found
                minIndex = j;                   // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        printArray(arr, n);                     // Print the array after each insertion
    }
}

// Iterate through the array and compare adjacent elements
// If the current element is greater than the next element, swap them
// Repeat the process for all elements in the array
// The process is repeated until no swaps are needed, indicating that the array is sorted
// Time Complexity: O(n^2) in the worst case, O(n) in the best case
void bubbleSort(int* arr, int n) {
    printf("\nBubble Sort Algorithm...\n");
    printArray(arr, n);

    for (int i = 0; i < n - 1; i ++) {              // Iterate through the array
        for (int j = 0; j < n - i - 1; j ++) {      // Last i elements are already sorted
            if (arr[j] > arr[j + 1]) {              // If the current element is greater than the next element

                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                printArray(arr, n);                 // Print the array after each swap
            }
        }
    }
}