// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;
};

struct CircularQueue* createQueue(int cap) {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->arr      = (int*)malloc(cap * sizeof(int));
    q->front    = 0;
    q->rear     = -1;
    q->capacity = cap;
    q->size     = 0;
    return q;
}

void enqueue(struct CircularQueue* q, int val) {
    if (q->size == q->capacity) {
        printf("Queue Full\n");
        return;
    }
    q->rear       = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

void dequeue(struct CircularQueue* q) {
    if (q->size == 0) {
        printf("Queue Empty\n");
        return;
    }
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void display(struct CircularQueue* q) {
    for (int i = 0; i < q->capacity; i++) {
        int idx = (q->front + i) % q->capacity;
        printf("%d", q->arr[idx]);
        if (i < q->capacity - 1)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct CircularQueue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    free(q->arr);
    free(q);

    return 0;
}