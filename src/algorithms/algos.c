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
// Key words: Insert -> Place
void insertionSort(int* arr, int n) {
    printf("\nInsertion Sorting Algorithm...\n");
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
// Key words: Select -> Choose
void selectionSort(int* arr, int n) {
    printf("\nSelection Sorting Algorithm...\n");
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
// Key words: Bubble -> (Iterate) Up
void bubbleSort(int* arr, int n) {
    printf("\nBubble Sorting Algorithm...\n");
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



// Merge Sort is a recurisve, divide and conquer algorithm
// Divide the array into two halves, sort them and merge them
// Time Complexity: O(n log n) in all cases
// Key words: Merge -> Combine
void mergeArrays(int* arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // Create temporary arrays
    int leftArr[leftSize], rightArr[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Initialize indices for merging
    int i = 0;  // Index for left subarray
    int j = 0;  // Index for right subarray
    int k = left;  // Index for merged array

    printf("\nMerging subarrays:\n");
    printf("Left:  "); printArray(leftArr, leftSize);
    printf("Right: "); printArray(rightArr, rightSize);

    // Merge temp arrays back into arr[left..right]
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            printf("Taking %d from left\n", leftArr[i]);
            
            arr[k] = leftArr[i];
            i++;
        } else {
            printf("Taking %d from right\n", rightArr[j]);

            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[] if any
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[] if any
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    /* Example visual for portion above:

                   i
    leftArr =   4, 9, 12

                   j
    rightArr =  5, 8, 14

                      k
    arr =       4, 5, ...

    i iterates through leftArr
    j iterates through rightArr
    k iterates through merged arr

    compare leftArr[i] and rightArr[j]:
        if leftArr[i] <= rightArr[j], 
            then arr[k] = leftArr[i]
            else arr[k] = rightArr[j]
        (i++ or j++) and k++ respectively
    */
}

void mergeRecursion(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;            // Find the middle point

        printf("\nSplitting array at index %d:\n", mid);
        printArray(arr + left, right - left + 1);

        mergeRecursion(arr, left, mid);                 // Sort the first half; from start to mid
        mergeRecursion(arr, mid + 1, right);            // Sort the second half; from mid + 1 to end
        mergeArrays(arr, left, mid, right);             // Merge the sorted halves
    }
}

void mergeSort(int* arr, int n) {
    printf("\nMerge Sorting Algorithm...\n");
    printArray(arr, n);

    mergeRecursion(arr, 0, n - 1);                      // Call the recursive function to sort the array
}



// Quick Sort is a recursive, divide and conquer algorithm
// Choose a pivot element, partition the array into two halves, sort them and merge them
// Time Complexity: O(n log n) in all cases
// Key words: Quick -> Pivot/Partition
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low;

    printf("\nPivot: %d\n", pivot);

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }

        printf("\narr[j] = %d\n", arr[j]);
        printf("arr[i] = %d\n", arr[i]);
        printArray(arr, high + 1);
    }

    /* Example visual for portion above:
    
    j
    6 3 7 5 1 2 [4]
    i
    6 (value of arr[j]) < 4 (pivot)? No, j++

      j
    6 3 7 5 1 2 [4]
    i
    3 < 4? Yes, swap arr[i] & arr[j], and i++ & j++

        j
    3 6 7 4 5 1 2 [4]
      i
    7 < 4? No, j++

          j
    3 6 7 5 1 2 [4]
      i
    5 < 4? No, j++

            j
    3 6 7 5 1 2 [4]
      i

    ... 
    Repeats until j !< high:
    ...

                 j
    3 1 2 5 6 7 [4]
          i
    
    Finally, swap arr[i] & arr[high]:
    3 1 2 4 6 7 [5]
    */

    swap(&arr[i], &arr[high]);
    printf("\narr[i] (pivot) = %d\n", arr[i]);
    printf("arr[high] = %d\n", arr[high]);

    return i;                           // Return the pivot value, which we know is currently index i
}

void quickSortRecursion(int* arr, int low, int high){
    if(low < high) {
        int pivot = partition(arr, low, high);                  // Call the partition function to find the pivot index
        quickSortRecursion(arr, low, pivot - 1);                // Recursively sort the left half
        quickSortRecursion(arr, pivot + 1, high);               // Recursively sort the right half
    }
}

void quickSort(int* arr, int n){
        printf("\nQuick Sorting Algorithm...\n");
    printArray(arr, n);

    quickSortRecursion(arr, 0, n - 1);                // Call the recursive function to sort the array
}

/* Example visual for quick sorting algorithm:

Assume array = [6, 3, 7, 5, 1, 2 4]

1. Choose a pivot element (last element in this case)

    6 3 7 5 1 2 [4]

2. Partition the array into two halves, one with elements less than the pivot and one with elements greater than the pivot

    6 3 7 5 1 2 [4]
                 v
           3 1 2 4 6 7 5

3. Recursively apply the same process to the left and right halves

    6 3 7 5 1 2 [4]
                 v
         3 1 [2] 4 6 7 [5]
              v         v
            1 2 3       5 7 [6]
                             v
                             6 7
              
4. Repeat until the base case is reached (when the array has one or zero elements)
*/