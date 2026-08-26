#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

void traverse(struct node *ptr ){
    while(ptr!=NULL){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}


void manual_linkedlist(){
    struct node *head;
    struct node *second;
    struct node *third;
    
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    
    traverse(head);
}

void user_linkedList(){
    int n;
    printf("Enter the number node you want:");
    scanf("%d",&n);
    struct node *head=NULL;
    struct node *current;
    struct node *ptr=NULL;
    for(int a=0;a<n;a++){
     current=(struct node *)malloc(sizeof(struct node));
     printf("Enter the number for linked list:");
     scanf("%d",&current->data);
     if(head==NULL){
         head=current;
         ptr=current;
     }else{
         ptr->next=current;
         ptr=current;
     }
    }
    traverse(head);
}

 int main(){
     
     manual_linkedlist();
     user_linkedList();
     return 0;
 }