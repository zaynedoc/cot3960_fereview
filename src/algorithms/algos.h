/*
Runtime Complexities:

Insertion Sort:
- Best case: O(n) when array is nearly sorted
- Average case: O(n^2)
- Worst case: O(n^2) when array is reverse sorted

Selection Sort:
- Best case: O(n^2)
- Average case: O(n^2)
- Worst case: O(n^2)

Bubble Sort:
- Best case: O(n) when array is already sorted
- Average case: O(n^2)
- Worst case: O(n^2) when array is reverse sorted

Merge Sort:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n log n)

Quick Sort:
- Best case: O(n log n)
- Average case: O(n log n)
- Worst case: O(n^2) when pivot is always smallest/largest element
*/

void printArray(int* arr, int size);

void insertionSort(int* arr, int n);
void selectionSort(int* arr, int n);
void bubbleSort(int* arr, int n);

void mergeSort(int* arr, int n);
void mergeRecursion(int* arr, int left, int right);
void mergeArrays(int* arr, int left, int mid, int right);

void swap(int* a, int* b);
void quickSort(int* arr, int n);
void quickSortRecursion(int* arr, int low, int high);
int partition(int* arr, int low, int high);