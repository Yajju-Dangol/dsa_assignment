# Program 1: Balanced Parentheses Checker

This program checks whether the parentheses (round `()`, curly `{}`, and square `[]`) in a given expression are balanced or not. To do this, it uses a **stack**, which follows the **Last-In-First-Out (LIFO)** principle.

---

## 1. Data Structure Used

### Stack
A stack is used to store opening brackets while scanning the expression.

**Stack contains:**
- `items[MAX_SIZE]` → an array that stores opening brackets.
- `top` → stores the index of the top element.
  - When `top = -1`, the stack is empty.

---

## 2. Functions Used in the Program

### `initialize(Stack *s)`
- Initializes the stack.
- Sets `top` to `-1`, meaning the stack is empty.
- Called before using the stack.

---

### `isFull(Stack *s)`
- Checks whether the stack is full.
- Returns `true` if `top == MAX_SIZE - 1`.
- Otherwise, returns `false`.

---

### `isEmpty(Stack *s)`
- Checks whether the stack is empty.
- Returns `true` if `top == -1`.
- Otherwise, returns `false`.

---

### `push(Stack *s, char value)`
- Pushes a character onto the stack.
- If the stack is full, prints an error message.
- Otherwise, increments `top` and stores the character.

---

### `pop(Stack *s)`
- Removes and returns the top element of the stack.
- If the stack is empty, prints an error and returns `'\0'`.
- Otherwise, returns the top element and decreases `top`.

---

### `isMatchingPair(char open, char close)`
- Checks whether an opening bracket matches a closing bracket.
- Matching pairs:
  - `(` and `)`
  - `{` and `}`
  - `[` and `]`
- Returns `true` if they match, otherwise `false`.

---

### `areParenthesesBalanced(char exp[])`
This function contains the main logic of the program.

**Working steps:**
1. Create and initialize an empty stack.
2. Traverse the expression character by character.
3. Push opening brackets (`(`, `{`, `[`) onto the stack.
4. When a closing bracket (`)`, `}`, `]`) is found:
   - If the stack is empty, the expression is unbalanced.
   - Pop the top element and check if it matches the closing bracket.
5. After the traversal:
   - If the stack is empty, parentheses are balanced.
   - Otherwise, they are not balanced.

---

## 3. Main Function (`main()`)

The `main()` function is used to test the program.

It:
1. Defines three test expressions:
   - `a + (b - c) * (d`
   - `m + [a - b * (c + d * {m)]`
   - `a + (b - c)`
2. Calls `areParenthesesBalanced()` for each expression.
3. Prints whether the result is **Balanced** or **Not Balanced**.

---

## 4. Sample Output
Test Case 1: a + (b - c) * (d
Result: Not Balanced

Test Case 2: m + [a - b * (c + d * {m)]
Result: Not Balanced

Test Case 3: a + (b - c)
Result: Balanced
