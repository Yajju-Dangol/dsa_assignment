#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->data[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char ch = infix[i];
        
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
        i++;
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (isOperator(ch)) {
            int val2 = pop(&s);
            int val1 = pop(&s);
            
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': push(&s, (int)pow(val1, val2)); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char infix[] = "3+4*2/(1-5)^2"; // Example expression
    char postfix[MAX];
    
    printf("Infix Expression: %s\n", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);
    
    return 0;
}
