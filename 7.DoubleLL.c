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

void backwardtraverse(struct node *ptr){
    printf("BACKWARd");
    while(ptr!=NULL){
        printf("\nElement:%d\n",ptr->data);
        ptr=ptr->prev;
    }
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

	traverse(head);

}

void userLinkedList() {
	int n;
	printf("Enter the number of node you want:");
	scanf("%d",&n);
	struct node *head=NULL;
	struct node *ptr=NULL;
	struct node *current;

	for(int a=0; a<n; a++) {
		current=(struct node *)malloc(sizeof(struct node));
		printf("Enter the number:");
		scanf("%d",&current->data);

		current->prev=NULL;
		current->next=NULL;

        if(head==NULL){
            head=current;
        }else{
            ptr->next=current;
            current->prev=ptr;
        }
      ptr=current;
	}
	traverse(head);
	backwardtraverse(ptr);
}

int main() {
	printf("double linked list\n");
	manualLinkedlist();
	userLinkedList();
	return 0;
}