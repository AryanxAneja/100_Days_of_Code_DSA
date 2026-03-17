// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear  = NULL;
    return q;
}

void enqueue(struct Queue* q, int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = node;
        q->rear  = node;
    } else {
        q->rear->next = node;
        q->rear       = node;
    }
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        exit(1);
    }
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

void display(struct Queue* q) {
    struct Node* curr = q->front;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf(" ");
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    display(q);

    return 0;
}