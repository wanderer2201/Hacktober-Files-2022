#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct stack *ptr)
{
    if ((isFull(ptr)))
    {
        printf("Stack Overflow..\n\n");
    }
    else
    {
        int data;
        printf("Enter Ur No: ");
        scanf("%d", &data);
        ptr->top++;
        ptr->arr[ptr->top] = data;
        printf("element pushed..\n\n");
    }

    return 1;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        printf("%d Item Is Poped\n\n", ptr->arr[ptr->top]);
        ptr->top--;
    }
    return 1;
}

int display(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        printf("Elements Are: ");
        for (int i = 0; i < ptr->top + 1; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n\n");
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    while (1)
    {
        int choice;
        printf("1.Push\n2.Pop\n3.display\n4.Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Enter Correct Choice..\n\n");
            break;
        }
    }

    return 0;
}
