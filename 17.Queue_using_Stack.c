#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push into stack1
void push1(int x) {
    if (top1 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack1[++top1] = x;
}

void push2(int x) {
    if (top2 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack2[++top2] = x;
}

// Pop 
int pop1() {
    return stack1[top1--];
}

int pop2() {
    return stack2[top2--];
}

// Enqueue operation
void enqueue(int x) {
    push1(x);
    printf("%d inserted into queue\n", x);
}

// Dequeue operation
int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    return pop2();
}

// Display queue
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Deleted: %d\n", dequeue());
    printf("Deleted: %d\n", dequeue());

    enqueue(40);

    display();

    return 0;
}
