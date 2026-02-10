#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To verify the heap property for Max Heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// To build a Max Heap from an array
void buildMaxHeap(int arr[], int n) {
    // Index of the last non-leaf node
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// To verify the heap property for Min Heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// To build a Min Heap from an array
void buildMinHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Create a copy for Min Heap since Build Heap modifies the array
    int arrMin[n];
    for(int i=0; i<n; i++) arrMin[i] = arr[i];

    printf("Original Array:\n");
    printArray(arr, n);

    buildMaxHeap(arr, n);
    printf("Max Heap:\n");
    printArray(arr, n);

    buildMinHeap(arrMin, n);
    printf("Min Heap:\n");
    printArray(arrMin, n);

    return 0;
}
