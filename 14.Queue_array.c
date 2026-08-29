#include <stdio.h>
#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue() {
	int x;

	printf("Enter the number: ");
	scanf("%d", &x);

	if (rear == MAX - 1) {
		printf("Overflow\n");
	}
	else if (rear == -1 && front == -1) {
		front = rear = 0;
		queue[rear] = x;
	}
	else {
		rear++;
		queue[rear] = x;
	}
}

void dequeue() {
	if (front == -1 && rear == -1) {
		printf("Underflow\n");
	}
	else if (front == rear) {
		printf("Removed element: %d\n", queue[front]);
		front = rear = -1;
	}
	else {
		printf("Removed element: %d\n", queue[front]);
		front++;
	}
}

void display() {
	if (front == -1 && rear == -1) {
		printf("Queue is empty\n");
	}
	else {
		for (int a = front; a <= rear; a++) {
			printf("Element: %d\n", queue[a]);
		}
	}
}

void peek() {
	if (front == -1 && rear == -1) {
		printf("Queue is empty\n");
	}
	else {
		printf("Front element: %d\n", queue[front]);
	}
}

int main() {
	printf("Queue in array\n");

	enqueue();
	enqueue();

	display();

	peek();

	dequeue();
	dequeue();

	display();

	return 0;
}