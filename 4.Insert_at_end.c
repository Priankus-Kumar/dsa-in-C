#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};
// traverse all the element the in LinkedList
void traverse(struct node *ptr ) {
	while(ptr!=NULL) {
		printf("element:%d\n",ptr->data);
		ptr=ptr->next;
	}
}

// insert at End
void insertEnd(struct node **head,int data) {
	struct node *ptr;

	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;

	while(*head!=NULL) {
		head = &(*head)->next;
	}
    *head=ptr;
}

void manual_linkedlist() {
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

	insertBegin(&head,5);
	insertEnd(&head,6);
	traverse(head);
}

int main() {
	manual_linkedlist();
	return 0;
}