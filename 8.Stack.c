#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;



// Display operation
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");

        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    // call the method from the operation_Stack.c
    
    // push(10);
    // push(20);
    // push(30);

    // display();

    // pop();

    // display();

    return 0;
}