#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void traverse(struct node *ptr){
    while(ptr!=NULL){
        printf("Element:%d",ptr->data);
        ptr=ptr->next;
    }
}

void DeleteBegin(struct node **head){
    struct nod *ptr;
    ptr=*head;   //save the old head
    *head=(*head)->next;   //move to the next head
 	(*head)->prev = NULL;
    free(ptr);   //free old head
}

void main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head=(struct node *)malloc(sizeof(struct node ));
    second=(struct node *)malloc(sizeof(struct node ));
    third=(struct node *)malloc(sizeof(struct node ));

    head->data=1;
    head->prev=NULL;
    head->next=second;
    
    second->data=1;
    second->prev=head;
    second->next=third;

    third->data=1;
    third->prev=second;
    third->next=NULL;

    DeleteBegin(&head);
    traverse(head);
}