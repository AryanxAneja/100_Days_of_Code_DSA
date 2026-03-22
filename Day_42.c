// Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>

void reverseQueue(int* queue, int size) {
    int* stack = malloc(size * sizeof(int));
    int top = -1;

    for (int i = 0; i < size; i++)
        stack[++top] = queue[i];

    for (int i = 0; i < size; i++)
        queue[i] = stack[top--];

    free(stack);
}

int main() {
    int queue[] = {1, 2, 3, 4, 5};
    int size = 5;

    reverseQueue(queue, size);

    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);

    return 0;
}