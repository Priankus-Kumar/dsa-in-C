#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *top=NULL;

void pushLinkedList() {
	int x;
	printf("Enter the number:");
	scanf("%d",&x);

	struct node * value;
	value=(struct node *)malloc(sizeof(struct node));
	value->data=x;
	value->next=top;

	top=value;
}

void peekLinkedList(){
    if(top==0){
        printf("stack is empty");
    }else{
        printf("the top element is:%d\n",top->data);
    }
}

void popLinkedList(){
    if(top==NULL){
        printf("stack is empty");
    }else{
        struct node *value;
        value=top;
        printf("\n%d ->popped from stack\n", top->data);
        top=top->next;
        free(value);
    }
}

void displayStackLL() {
	printf("Display the stack\n");
	struct node *temp=top;
	while (temp != NULL) {
		printf("element:%d\n", temp->data);
		temp = temp->next;
	}
}

void userdefinedStorevalue() {
	int n;
	printf("Enter the node you want:");
	scanf("%d",&n);
	for(int a=0; a<n; a++) {
		pushLinkedList();
	}
}

void main() {
	printf("**************stack with Lnked list**********\n");
	userdefinedStorevalue();
	peekLinkedList();
	displayStackLL();
	popLinkedList();
	peekLinkedList();
	displayStackLL();
    
}