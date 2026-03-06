// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* append(struct node* head, int data){
    struct node* newNode = createNode(data);
    if(head == NULL)
        return newNode;

    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int length(struct node* head){
    int count = 0;
    struct node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

struct node* rotateRight(struct node* head, int k){
    if(head == NULL || head->next == NULL)
        return head;

    int len = length(head);
    k = k % len;
    if(k == 0)
        return head;

    struct node* temp = head;
    int steps = len - k - 1;

    for(int i = 0; i < steps; i++)
        temp = temp->next;

    struct node* newHead = temp->next;
    temp->next = NULL;

    struct node* tail = newHead;
    while(tail->next != NULL)
        tail = tail->next;

    tail->next = head;

    return newHead;
}

int main(){
    int n, x, k;
    struct node* head = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        head = append(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}