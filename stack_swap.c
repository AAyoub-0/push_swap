#include "main.h"

void swap_stack(t_stack *stack)
{
    int tmp;
    if (stack->top < 1)
    {
        printf("Not enough elements in the stack\n");
        return;
    }
    tmp = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = tmp;
}