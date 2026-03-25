// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int   size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
    printf("Enqueued: %d\n", data);
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->head;
    int data   = temp->data;

    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;

    free(temp);
    q->size--;
    return data;
}

int peek(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->head->data;
}

int isEmpty(Queue* q) {
    return q->head == NULL;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue: [empty]\n");
        return;
    }
    printf("Queue (HEAD → TAIL): ");
    Node* curr = q->head;
    while (curr) {
        printf("%d → ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue* q) {
    while (!isEmpty(q))
        dequeue(q);
    free(q);
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Peek: %d\n", peek(q));
    printf("Size: %d\n", q->size);

    freeQueue(q);
    return 0;
}