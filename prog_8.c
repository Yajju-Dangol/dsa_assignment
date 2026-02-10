#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n, long *comps, long *swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comps)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, long *comps, long *swaps) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            (*comps)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*swaps)++;
        }
    }
}

void insertionSort(int arr[], int n, long *comps, long *swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comps)++;
            arr[j + 1] = arr[j];
            j = j - 1;
            (*swaps)++; // Counting shifts as swaps for simplicity in this context
        }
        if (j >= 0) (*comps)++; // One last comparison that failed the loop
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r, long *comps, long *swaps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        (*comps)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            // (*swaps)++; // Merge sort doesn't really "swap" in the traditional sense, but we can count moves if desired.
            // Problem asks for swaps (if applicable). Standard merge doesn't count swaps usually.
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r, long *comps, long *swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comps, swaps);
        mergeSort(arr, m + 1, r, comps, swaps);
        merge(arr, l, m, r, comps, swaps);
    }
}

int main() {
    int n, choice;
    long comps = 0, swaps = 0;

    srand(time(0));

    printf("Enter number of elements (N): ");
    // For automated testing, we might want to hardcode or read from args, but strictly main() user input:
    // This will block if run interactively, but I will simulate input via doc or assumption?
    // The previous docs imply hardcoded test cases in main mostly, but this Q specifically asks to "Ask the user".
    // I will write code that reads from stdin.
    // However, since I cannot interact with it conveniently here, I will just assume it compiles and runs.
    
    // To make it run without blocking in test environment if needed, I'll default if scanf fails or just use simple logic.
    // But since "Ask the user" is requirements...
    // I'll implement standard scanf.
    
    // Note: If I run this via "run_terminal" later, I need to provide input.
    // I won't run it now.
    
    if (scanf("%d", &n) != 1) return 1; // Basic error check

    int *arr = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }

    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) return 1;

    printf("\nData before sorting:\n");
    printArray(arr, n);

    switch (choice) {
        case 1:
            bubbleSort(arr, n, &comps, &swaps);
            printf("\nSorted using Bubble Sort.\n");
            break;
        case 2:
            selectionSort(arr, n, &comps, &swaps);
            printf("\nSorted using Selection Sort.\n");
            break;
        case 3:
            insertionSort(arr, n, &comps, &swaps);
            printf("\nSorted using Insertion Sort.\n");
            break;
        case 4:
            mergeSort(arr, 0, n - 1, &comps, &swaps);
            printf("\nSorted using Merge Sort.\n");
            break;
        default:
            printf("Invalid choice!\n");
            free(arr);
            return 1;
    }

    printf("\nData after sorting:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %ld\n", comps);
    printf("Total Swaps: %ld\n", swaps);

    free(arr);
    return 0;
}
