#include "main.h"

t_stack *stack_create(int size)
{
    t_stack *stack = malloc(sizeof(t_stack));
    stack->data = malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return (stack);
}

void stack_pop(t_stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return ;
    }
    stack->top--;
}

void stack_delete(t_stack *stack, int index)
{
    int i;

    if (index < 0 || index > stack->top)
    {
        printf("Index out of range\n");
        return ;
    }
    i = index;
    while (i < stack->top)
    {
        stack->data[i] = stack->data[i + 1];
        i++;
    }
    stack->top--;
}

void stack_destroy(t_stack *stack)
{
    free(stack->data);
    free(stack);
}
