# Program 4: Doubly Linked List Implementation

This program implements a **Doubly Linked List** (DLL) using a structure. It provides functionality to **insert a node after a given node** and **delete a specific node** from the list.

---

## 1. Data Structure Used

### Doubly Linked List Node
A structured data type `Node` is used to represent each element in the list.

**Node contains:**
- `data` → an integer value.
- `prev` → a pointer to the previous node.
- `next` → a pointer to the next node.

---

## 2. Functions Used in the Program

### `createNode(int data)`
- Allocates memory for a new node.
- Initializes `data`, `prev` to `NULL`, and `next` to `NULL`.

---

### `insertAfter(Node* prev_node, int new_data)`
- Inserts a new node after a given `prev_node`.
- Logic:
  1. Check if `prev_node` is `NULL`.
  2. Create a new node.
  3. Update pointers:
     - `new_node->next` = `prev_node->next`
     - `prev_node->next` = `new_node`
     - `new_node->prev` = `prev_node`
     - If `new_node->next` is not `NULL`, update `new_node->next->prev` to `new_node`.

---

### `deleteNode(Node** head_ref, Node* del)`
- Deletes the node `del` from the list.
- Logic:
  1. If `head` or `del` is `NULL`, return.
  2. If `del` is the head node, update `head` to `del->next`.
  3. If `del->next` is not `NULL`, update `del->next->prev`.
  4. If `del->prev` is not `NULL`, update `del->prev->next`.
  5. Free the memory of `del`.

---

### `printList(Node* node)`
- Traverses the list and prints data in the format `data <-> data ... -> NULL`.

---

## 3. Main Function (`main()`)

The `main()` function:
1. Creates an initial DLL: `10 <-> 20 <-> 30 -> NULL`.
2. Inserts `25` after `20` (the second node).
3. Deletes `20` from the list.
4. Deletes the head node (`10`) from the list.
5. Prints the list after each operation to demonstrate correctness.

---

## 4. Sample Output

```
Initial Doubly Linked List:
10 <-> 20 <-> 30 -> NULL

Inserting 25 after 20...
10 <-> 20 <-> 25 <-> 30 -> NULL

Deleting 20...
10 <-> 25 <-> 30 -> NULL

Deleting head (10)...
25 <-> 30 -> NULL
```
