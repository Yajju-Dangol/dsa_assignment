# Program 6: Min and Max Heap

This program constructs a **Max Heap** and a **Min Heap** from a given unsorted array of integers. Max Heap and Min Heap are binary trees that satisfy the heap property:
- **Max Heap:** The key at the root must be maximum among all keys present in the binary heap.
- **Min Heap:** The key at the root must be minimum among all keys present in the binary heap.

---

## 1. Data Structure Used

### Array
The heap is represented using an array. For a node at index `i`:
- Left Child is at index `2*i + 1`
- Right Child is at index `2*i + 2`
- Parent is at index `(i-1)/2`

---

## 2. Functions Used in the Program

### `swap(int *a, int *b)`
- Swaps the values of two integers.

---

### `maxHeapify(int arr[], int n, int i)`
- Ensures the subtree rooted at index `i` satisfies the Max Heap property.
- If the root is smaller than its children, it is swapped with the largest child, and `maxHeapify` is called recursively on the affected subtree.

### `buildMaxHeap(int arr[], int n)`
- Converts an arbitrary array into a Max Heap.
- Calls `maxHeapify` starting from the last non-leaf node up to the root.

---

### `minHeapify(int arr[], int n, int i)`
- Ensures the subtree rooted at index `i` satisfies the Min Heap property.
- If the root is larger than its children, it is swapped with the smallest child, and `minHeapify` is called recursively.

### `buildMinHeap(int arr[], int n)`
- Converts an arbitrary array into a Min Heap.
- Calls `minHeapify` starting from the last non-leaf node up to the root.

---

### `printArray(int arr[], int n)`
- Prints the elements of the array.

---

## 3. Main Function (`main()`)

The `main()` function:
1. Defines an unsorted array: `{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}`.
2. Creates a copy of the array for Min Heap operations.
3. Calls `buildMaxHeap()` on the first array and prints the result.
4. Calls `buildMinHeap()` on the second array and prints the result.

---

## 4. Sample Output

```
Original Array:
1 3 5 4 6 13 10 9 8 15 17 
Max Heap:
17 15 13 9 6 5 10 4 8 3 1 
Min Heap:
1 3 5 4 6 13 10 9 8 15 17 
```
