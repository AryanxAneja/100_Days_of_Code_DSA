// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = createNode(l1->data);
            l1 = l1->next;
        } else {
            tail->next = createNode(l2->data);
            l2 = l2->next;
        }
        tail = tail->next;
    }

    while (l1 != NULL) {
        tail->next = createNode(l1->data);
        l1 = l1->next;
        tail = tail->next;
    }

    while (l2 != NULL) {
        tail->next = createNode(l2->data);
        l2 = l2->next;
        tail = tail->next;
    }

    return dummy.next;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);

    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);

    struct Node* merged = mergeLists(list1, list2);

    display(merged);

    return 0;
}