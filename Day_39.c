// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>
#include <string.h>

#define MAX 100005

int heap[MAX], size = 0;

void swap(int i, int j) {
    int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

void insert(int x) {
    heap[++size] = x;
    int i = size;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(i, i / 2);
        i /= 2;
    }
}

int extractMin() {
    if (size == 0) return -1;
    int min = heap[1];
    heap[1] = heap[size--];
    int i = 1;
    while (1) {
        int smallest = i;
        if (2*i <= size && heap[2*i] < heap[smallest]) smallest = 2*i;
        if (2*i+1 <= size && heap[2*i+1] < heap[smallest]) smallest = 2*i+1;
        if (smallest == i) break;
        swap(i, smallest);
        i = smallest;
    }
    return min;
}

int peek() {
    return size == 0 ? -1 : heap[1];
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x; scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}