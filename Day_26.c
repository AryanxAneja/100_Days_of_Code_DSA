// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void traverse(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int n, x;
    struct Node* head = NULL;
    printf("Enter no of nodes you want to create: ");
    scanf("%d", &n);
    printf("Enter the elements:");

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    traverse(head);

    return 0;
}