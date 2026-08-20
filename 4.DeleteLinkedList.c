#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

// ==========================================================
// Delete from the linkedList
// ==========================================================

struct node  *DeleteFirst(struct node *head){
    struct node *ptr=head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the last element
struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

// Case 3: Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}
// ==========================================================
// ==========================================================
// ==========================================================



int main(){

    struct node *head;
    struct node *second;
    struct node *third;
    
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    
    head->data=10;
    head->next=second;
    second->data=40;
    second->next=third;
    third->data=30;
    third->next=NULL;
    
    traversal(head);

   head= DeleteFirst(head); 
   traversal(head)
}