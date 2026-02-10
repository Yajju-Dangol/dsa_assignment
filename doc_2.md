# Program 2: Infix to Postfix Conversion and Evaluation

This program converts an arithmetic expression from **Infix notation** to **Postfix notation** and then evaluates the result. It uses a **Stack** data structure to handle operator precedence and evaluation.

---

## 1. Data Structure Used

### Stack
A stack is used for two purposes:
1. To store operators during the infix-to-postfix conversion.
2. To store operands during the postfix evaluation.

**Stack contains:**
- `data[MAX]` → an integer array that stores operands (for evaluation) and operators (as ASCII values for conversion).
- `top` → stores the index of the top element.
  - When `top = -1`, the stack is empty.

---

## 2. Functions Used in the Program

### `initStack(Stack *s)`
- Initializes the stack.
- Sets `top` to `-1`.

---

### `push(Stack *s, int value)`
- Pushes an integer (or character cast to int) onto the stack.
- Checks for stack overflow.

---

### `pop(Stack *s)`
- Removes and returns the top element of the stack.
- Checks for stack underflow.

---

### `precedence(char op)`
- Returns the precedence level of an operator.
- `^` has the highest precedence (3).
- `*`, `/` have medium precedence (2).
- `+`, `-` have the lowest precedence (1).

---

### `infixToPostfix(char *infix, char *postfix)`
- Converts the given infix expression to postfix.
- Scans the infix expression:
  - If operand, add to postfix string.
  - If `(`, push to stack.
  - If `)`, pop and add to postfix string until `(` is found.
  - If operator, pop operators with higher or equal precedence, then push current operator.

---

### `evaluatePostfix(char *postfix)`
- Evaluates the postfix expression.
- Scans the postfix expression:
  - If operand, push to stack.
  - If operator, pop two operands, perform operation, and push result back.
- Returns the final result.

---

## 3. Main Function (`main()`)

The `main()` function:
1. Defines an infix expression (e.g., `3+4*2/(1-5)^2`).
2. Calls `infixToPostfix()` to convert it.
3. Prints the postfix expression.
4. Calls `evaluatePostfix()` to compute the result.
5. Prints the final evaluation result.

---

## 4. Sample Output

```
Infix Expression: 3+4*2/(1-5)^2
Postfix Expression: 342*15-2^/+
Evaluation Result: 3
```
