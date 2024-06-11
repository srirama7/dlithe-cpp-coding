#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} Stack;

void initializeStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++s->top] = value;
    printf("%d pushed onto stack\n", value);
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return s->items[s->top--];
}

int main()
{
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
