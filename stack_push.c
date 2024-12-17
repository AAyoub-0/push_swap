#include "main.h"

void stack_push(t_stack *stack, int value)
{
    if (stack->top == stack->size - 1)
    {
        printf("Stack is full\n");
        return ;
    }
    stack->data[++stack->top] = value;
}

void stack_push_to(t_stack *stack_from, t_stack *stack_to)
{
    if (stack_from->top == -1)
    {
        printf("Stack 'from' is empty\n");
        return ;
    }
    if (stack_to->top == stack_to->size - 1)
    {
        printf("Stack 'to' is full\n");
        return ;
    }
    stack_push(stack_to, stack_from->data[0]);
    stack_delete(stack_from, 0);
}