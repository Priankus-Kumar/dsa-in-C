#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

void traverse(struct node *ptr) {
	while(ptr!=NULL) {
		printf("Element:%d\n",ptr->data);
		ptr=ptr->next;
	}
}

void startBegin(struct node **head,int data){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    
    ptr->data=data;
    ptr->next=*head;
    ptr->prev=NULL;
    
   *head=ptr;
}

void manualLinkedlist() {
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;

	head=(struct node *)malloc(sizeof(struct node));
	second=(struct node *)malloc(sizeof(struct node));
	third=(struct node *)malloc(sizeof(struct node));
	fourth=(struct node *)malloc(sizeof(struct node));

	head->data=1;
	head->next=second;
	head->prev=NULL;
	second->data=2;
	second->next=third;
	second->prev=head;
	third->data=3;
	third->next=fourth;
	third->prev=second;
	fourth->data=4;
	fourth->next=NULL;
	fourth->prev=third;

    startBegin(&head,5);
	traverse(head);
	backwardtraverse();

}



int main() {
	printf("double linked list\n");
	manualLinkedlist();
// 	userLinkedList();
	return 0;
}