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

// delete the head
void DeleteBegin(struct node **head){
    struct node *ptr;
    ptr=*head;
    *head=(*head)->next;
    free(ptr);
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

	DeleteBegin(&head);
	traverse(head);
}

int main() {
	manual_linkedlist();
// 	user_linkedList();
	return 0;
}