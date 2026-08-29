#include<stdio.h>
#define MAX 5

int stack[MAX];
int top= -1;

void push () {
	int x;
	if(top==MAX-1) {
		printf("overflow stack is full\n");
	} else {
		printf("Enter the number:");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}

void pop() {
	int x;
	if(top==-1) {
		printf("underflow emplty hai stack");
	} else {
		x=stack[top];
		top--;
		printf("removed element is:%d\n",x);
	}
}

void peek() {
	if(top==-1) {
		printf("no number is there");
	} else {
		printf("top element is:%d",stack[top]);
	}
}

void repeat() {
	for(int a=0; a<MAX; a++) {
		push();
	}
}

void display() {
	    printf("display the element\n");
	for(int a=top; a>=0; a--) {
		printf("element:%d\n",stack[a]);
	}
}

int main() {
	printf("\nstack\n");
	// 	repeat();
	push();
	push();
	push();
	display();
	pop();
	display();
	return 0;
}