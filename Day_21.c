// Problem: Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, value;
    printf("Enter the no of nodes that you want: ");
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &value);
    head = (struct node*)malloc(sizeof(struct node));
    head->data = value;
    head->next = NULL;
    temp = head;
    for(int i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}