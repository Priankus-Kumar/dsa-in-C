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
// delete the End
void DeleteEnd(struct node **head) {
	struct node *ptr;
	ptr=*head;

	if(ptr==NULL) {
		return;
	}
	if(ptr->next==NULL) {
		free(ptr);
		*head=NULL;
		return;
	}
	while (ptr->next->next != NULL){
		ptr = ptr->next;
    }

      free(ptr->next);
    ptr->next = NULL;
}
// manual_linkedlist
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


	DeleteEnd(&head);
	traverse(head);
}


int main() {
	manual_linkedlist();
	// 	user_linkedList();
	return 0;
}