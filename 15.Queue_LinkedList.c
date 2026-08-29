#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue() {
    int x;

    printf("Enter the number: ");
    scanf("%d", &x);

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
    }
    else {
        struct Node *temp = front;

        printf("Removed element: %d\n", front->data);

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    }
    else {
        struct Node *temp = front;

        while (temp != NULL) {
            printf("Element: %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front element: %d\n", front->data);
    }
}

int main() {
    printf("Queue using Linked List\n");

    enqueue();
    enqueue();
    enqueue();

    printf("\nQueue elements:\n");
    display();

    printf("\n");
    peek();

    printf("\n");
    dequeue();

    printf("\nQueue after dequeue:\n");
    display();

    return 0;
}
