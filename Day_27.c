// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int length(struct node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

struct node* advance(struct node* head,int k){
    while(k-- && head)
        head=head->next;
    return head;
}

int main(){
    int n,m,i,x;
    printf("Enter the no of nodes you want to create: ");
    scanf("%d",&n);
    struct node *head1=NULL,*tail1=NULL,*newnode;
    printf("Enter elements:");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;

        if(!head1){
            head1=tail1=newnode;
        }else{
            tail1->next=newnode;
            tail1=newnode;
        }
    }

    scanf("%d",&m);
    struct node *head2=NULL,*tail2=NULL;

    for(i=0;i<m;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;

        if(!head2){
            head2=tail2=newnode;
        }else{
            tail2->next=newnode;
            tail2=newnode;
        }
    }

    int len1=length(head1);
    int len2=length(head2);

    struct node *p1=head1,*p2=head2;

    if(len1>len2)
        p1=advance(p1,len1-len2);
    else
        p2=advance(p2,len2-len1);

    while(p1 && p2){
        if(p1->data==p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }

    printf("No Intersection");
    return 0;
}