#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void traverse(struct node *ptr ) {
	while(ptr!=NULL) {
		printf("element:%d\n",ptr->data);
		ptr=ptr->next;
	}
}

void insertBegin(struct node **head,int data) {
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	
	ptr->data=data;
	ptr->next=*head;

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
	traverse(head);
}

int main() {
	manual_linkedlist();
	return 0;
}