#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

/*
    Inputs: stack size
    Output: address of created stack
    Description: Initializes a stack using the static approach.
    However this doesn't have the feature of being freed once its usage is done.
*/
struct stack *create_static(int size)
{
    static struct stack mystack;
    mystack.arr = malloc(sizeof(int) * size);
    mystack.size = size;
    mystack.top = size - 1;
    return &mystack;
}

/*
    Inputs: stack size
    Output: address of created stack
    Description: Initializes a stack using the dynamic allocation.
*/
struct stack *create_dynamic(int size)
{
    struct stack *structPtr = malloc(sizeof(struct stack));
    structPtr->arr = malloc(sizeof(int) * size);
    structPtr->size = size;
    structPtr->top = size - 1;
    return structPtr;
}

/*
    Inputs: value to push, stack address
    Output: None
    Description: stores the given value into the stack.
*/
void push(int val, struct stack *stackPtr)
{
    if (0 <= stackPtr->top)
    {
        stackPtr->arr[stackPtr->top] = val;
        --(stackPtr->top);
    }
    else
    {
        printf("Stack is full!\n");
    }
}

/*
    Inputs: stack address
    Output: value
    Description: returns the value in the top of stack.
*/
int pop(struct stack *stackPtr)
{
    if (stackPtr->top < (stackPtr->size) - 1)
    {
        ++(stackPtr->top);
        return stackPtr->arr[stackPtr->top];
    }
    else
    {
        printf("Stack is empty!\n");
    }
}

/*
    Inputs: stack address
    Output: None
    Description: prints the stack values by removing all values in stack.
*/
void printStack(struct stack *stackPtr)
{
    while (stackPtr->top < (stackPtr->size) - 1)
    {
        printf("%d\n", pop(stackPtr));
    }
    printf("stack is empty!!\n");
}

int main()
{
    struct stack *ptr;
    ptr = create(5);
    pop(ptr);
    push(3, ptr);
    push(5, ptr);
    push(6, ptr);
    pop(ptr);
    push(3, ptr);
    push(5, ptr);
    push(6, ptr);
    push(3, ptr);
    printStack(ptr);
    pop(ptr);
    return 0;
}