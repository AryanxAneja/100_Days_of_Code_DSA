// Problem: Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top, char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char c = temp->data;
    *top = (*top)->next;
    free(temp);
    return c;
}

char peek(Node* top) {
    return (top == NULL) ? '\0' : top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(char* exp) {
    Node* stack = NULL;
    int i = 0, k = 0;
    char output[256];

    while (exp[i] != '\0') {
        char c = exp[i];

        if (isalnum(c)) {
            output[k++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (peek(stack) != '(')
                output[k++] = pop(&stack);
            pop(&stack);
        } else if (isOperator(c)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(c))
                output[k++] = pop(&stack);
            push(&stack, c);
        }
        i++;
    }

    while (!isEmpty(stack))
        output[k++] = pop(&stack);

    output[k] = '\0';
    printf("%s\n", output);
}

int main() {
    char exp[256];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}