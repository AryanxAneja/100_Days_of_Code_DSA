// Problem: Deque (Double-Ended Queue) A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int val) {
    if (front == 0) {
        printf("Deque is full\n");
        return;
    }
    if (empty()) {
        front = rear = MAX / 2;
    } else {
        front--;
    }
    deque[front] = val;
}

void push_back(int val) {
    if (rear == MAX - 1) {
        printf("Deque is full\n");
        return;
    }
    if (empty()) {
        front = rear = MAX / 2;
    } else {
        rear++;
    }
    deque[rear] = val;
}

void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void get_front() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void get_back() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort_deque() {
    for (int i = front; i <= rear; i++)
        for (int j = i + 1; j <= rear; j++)
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
}

void print_deque() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int val;
            scanf("%d", &val);
            push_front(val);

        } else if (strcmp(op, "push_back") == 0) {
            int val;
            scanf("%d", &val);
            push_back(val);

        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();

        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();

        } else if (strcmp(op, "front") == 0) {
            get_front();

        } else if (strcmp(op, "back") == 0) {
            get_back();

        } else if (strcmp(op, "empty") == 0) {
            printf("%s\n", empty() ? "true" : "false");

        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());

        } else if (strcmp(op, "clear") == 0) {
            clear();

        } else if (strcmp(op, "reverse") == 0) {
            reverse();

        } else if (strcmp(op, "sort") == 0) {
            sort_deque();

        } else if (strcmp(op, "print") == 0) {
            print_deque();
        }
    }
    return 0;
}