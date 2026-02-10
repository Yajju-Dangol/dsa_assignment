# Program 8: Sorting Algorithms

This program generates a list of **N** random integers and allows the user to sort them using one of the following algorithms:
1. **Bubble Sort**
2. **Selection Sort**
3. **Insertion Sort**
4. **Merge Sort**

It also displays the number of **comparisons** and **swaps** performed by the chosen algorithm.

---

## 1. Data Structure Used

### Array
An integer array `arr[N]` is used to store the random numbers. The memory for this array is dynamically allocated using `malloc` based on the user's input `N`.

---

## 2. Functions Used in the Program

### `bubbleSort(int arr[], int n, long *comps, long *swaps)`
- Sorts the array by repeatedly swapping adjacent elements if they are in the wrong order.
- Tracks comparisons and swaps.

### `selectionSort(int arr[], int n, long *comps, long *swaps)`
- Sorts the array by repeatedly finding the minimum element from the unsorted part and putting it at the beginning.
- Tracks comparisons and swaps.

### `insertionSort(int arr[], int n, long *comps, long *swaps)`
- Sorts the array by building a sorted array one item at a time. It picks elements from the unsorted part and places them at the correct position in the sorted part.
- Tracks comparisons and shifts (swaps).

### `mergeSort(int arr[], int l, int r, long *comps, long *swaps)`
- A divide-and-conquer algorithm.
- Recursively divides the array into two halves, sorts them, and then merges the sorted halves using the `merge()` function.
- Efficient for large datasets ($O(n \log n)$).

---

## 3. Main Function (`main()`)

The `main()` function:
1. Asks the user for the number of elements **N**.
2. Generates **N** random integers between 1 and 1000.
3. Displays a menu to choose a sorting algorithm.
4. Prints the array **before sorting**.
5. calls the selected sorting function.
6. Prints the array **after sorting**.
7. Displays the total number of **comparisons** and **swaps** performed.
8. Frees the allocated memory.

---

## 4. Sample Output

```
Enter number of elements (N): 10
Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

Data before sorting:
482 145 923 12 567 348 901 22 10 78 

Sorted using Bubble Sort.

Data after sorting:
10 12 22 78 145 348 482 567 901 923 

Total Comparisons: 45
Total Swaps: 26
```
