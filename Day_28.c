// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,i;
    printf("Enter the no of nodes that you want to make:");
    scanf("%d",&n);
    printf("Enter the elements:");
    struct node *head=NULL,*temp=NULL,*newnode;

    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp->next=head;

    struct node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);

    return 0;
}