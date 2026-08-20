#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

 void CircularTraversal(struct node *head){
     struct node * ptr=head;
     do{
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
     }while(ptr != head);

}

int main(){
 
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = fifth;

    fifth->data = 1;
    fifth->next = head;
    
    
    CircularTraversal(head);

    return 0;
}