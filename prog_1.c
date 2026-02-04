#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char ch) {
    if (isFull(s)) return;
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top--];
}

bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalanced(char exp[]) {
    Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s) || !match(pop(&s), c))
                return false;
        }
    }
    return isEmpty(&s);
}

int main() {
    char e1[] = "a + (b - c) * (d";
    char e2[] = "m + [a - b * (c + d * {m)]";
    char e3[] = "a + (b - c)";

    printf("%s -> %s\n", e1, checkBalanced(e1) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", e2, checkBalanced(e2) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", e3, checkBalanced(e3) ? "Balanced" : "Not Balanced");

    return 0;
}
