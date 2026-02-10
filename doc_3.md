# Program 3: Reverse Linked List Traversal

This program implements a **Singly Linked List** and performs a reverse traversal using **recursion**. The traversal prints the elements of the list from the last node to the first node without reversing the actual links.

---

## 1. Data Structure Used

### Linked List Node
A structured data type `Node` is used to represent each element in the list.

**Node contains:**
- `data` → an integer value.
- `next` → a pointer to the next node in the list.

---

## 2. Functions Used in the Program

### `createNode(int data)`
- Allocates memory for a new node.
- Initializes `data` with the given value and `next` with `NULL`.
- Returns the pointer to the new node.

---

### `insertAtEnd(Node** head, int data)`
- Inserts a new node with the given data at the end of the list.
- If the list is empty, the new node becomes the head.
- Otherwise, traverses to the last node and updates its `next` pointer.

---

### `printList(Node* head)`
- Traverses the list from the head to the end.
- Prints the data of each node.

---

### `reverseTraversal(Node* head)`
- A recursive function to print the list in reverse order.
- **Base Case:** If `head` is `NULL`, return.
- **Recursive Step:** Call `reverseTraversal(head->next)`.
- **Action:** Print the `data` of the current node *after* the recursive call returns.

---

## 3. Main Function (`main()`)

The `main()` function:
1. Initializes an empty linked list (`head = NULL`).
2. Inserts integer values (10, 20, 30, 40, 50) into the list.
3. Prints the original list structure.
4. Calls `reverseTraversal()` to display the elements in reverse order.

---

## 4. Sample Output

```
Original Linked List:
10 -> 20 -> 30 -> 40 -> 50 -> NULL
Reverse Traversal Output:
50 40 30 20 10 
```
