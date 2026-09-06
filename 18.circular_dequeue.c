#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Check if deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}
// Check if deque is empty
int isEmpty() {
    return front == -1;
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = value;
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    int i = front;

    printf("Deque: ");

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertRear(30);

    display();

    insertFront(5);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    insertFront(1);
    insertRear(40);
    display();

    return 0;
}


//using the linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert at front
void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        // First node
        front = rear = newNode;
        // Circular links
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = front;
        newNode->prev = rear;

        rear->next = newNode;
        front->prev = newNode;

        front = newNode;
    }
}

// Insert at rear
void insertRear(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        // First node
        front = rear = newNode;
        // Circular links
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = front;
        newNode->prev = rear;

        rear->next = newNode;
        front->prev = newNode;

        rear = newNode;
    }
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) {
        // Only one node
        front = rear = NULL;
    }
    else {
        front = front->next;

        front->prev = rear;
        rear->next = front;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from rear
void deleteRear() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = rear;

    if (front == rear) {
        // Only one node
        front = rear = NULL;
    }
    else {
        rear = rear->prev;

        rear->next = front;
        front->prev = rear;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display from front to rear
void display() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Deque: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertRear(30);

    display();

    insertFront(5);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    insertFront(1);
    insertRear(40);
    display();

    return 0;
}
