// Push operation
void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = data;
        printf("%d inserted\n", data);
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d deleted\n", stack[top]);
        top--;
    }
}

// peek
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}
