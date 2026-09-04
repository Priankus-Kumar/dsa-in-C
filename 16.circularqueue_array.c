#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int value){
    // Check if queue is full
    if ((rear + 1) % MAX == front){
        printf("Queue is Full!\n");
        return;
    }

    // First element
    if (front == -1){
        front = 0;
    }

    // Circular increment of rear
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}

// Dequeue operation
void dequeue(){
    int value;
    // Check if queue is empty
    if (front == -1){
        printf("Queue is Empty!\n");
        return;
    }
    value = queue[front];
    // If only one element is present
    if (front == rear){
        front = -1;
        rear = -1;
    }else{
        // Circular increment of front
        front = (front + 1) % MAX;
    }

    printf("%d deleted from queue.\n", value);
}

// Peek operation
void peek(){
    if (front == -1){
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front element = %d\n", queue[front]);
}

// Display operation
void display(){
    int i;
    if (front == -1){
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    i = front;
    while (1){
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    peek();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    peek();

    return 0;
}
