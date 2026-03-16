// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! Invalid postfix expression.\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int evaluatePostfix(char* expression) {
    Node* stack = NULL;
    char* token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && token[1] != '\0')) {
            push(&stack, atoi(token));
        } else if (strlen(token) == 1 &&
                   (token[0] == '+' || token[0] == '-' ||
                    token[0] == '*' || token[0] == '/')) {

            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) { printf("Division by zero!\n"); exit(1); }
                    result = a / b;
                    break;
                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    int finalResult = pop(&stack);

    while (!isEmpty(stack)) {
        pop(&stack);
    }

    return finalResult;
}

int main() {
    char expression[256];

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}