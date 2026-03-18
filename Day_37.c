// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>

int pq[1000];
int size = 0;

void insert(int x) {
    pq[size++] = x;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (pq[i] > pq[j]) {
                int temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
}

void delete() {
    if (size == 0)
        printf("-1\n");
    else {
        printf("%d\n", pq[0]);
        for (int i = 0; i < size - 1; i++)
            pq[i] = pq[i + 1];
        size--;
    }
}

void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {
            delete();
        } else if (op[0] == 'p') {
            peek();
        }
    }
    return 0;
}