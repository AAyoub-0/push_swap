/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:33 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/11 22:49:50 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    sort_two(t_stack *stack)
{
    if (stack->data[0] > stack->data[1])
        stack_swap(stack, true);
}

void    sort_three(t_stack *stack)
{
    if (is_sorted(stack))
        return ;
    if (is_sorted_desc(stack))
    {
        stack_rotate(stack, true);
        stack_swap(stack, true);
    }
    else if (stack->data[0] > stack->data[1] && stack->data[0] > stack->data[2])
        stack_rotate(stack, true);
    else if (stack->data[0] < stack->data[1] && stack->data[0] > stack->data[2])
        stack_reverse_rotate(stack, true);
    else if (stack->data[0] < stack->data[1] && stack->data[1] > stack->data[2])
    {
        stack_reverse_rotate(stack, true);
        stack_swap(stack, true);
    }
    else
        stack_swap(stack, true);
}

int get_min(t_stack *stack)
{
    int i;
    int min;

    i = 0;
    min = stack->data[0];
    while (i <= stack->top)
    {
        if (stack->data[i] < min)
            min = stack->data[i];
        i++;
    }
    return (min);
}

void    sort_four(t_stack *stack_a, t_stack *stack_b)
{
    int min;

    if (is_sorted(stack_a))
        return ;
    min = get_min(stack_a);
    while (stack_a->data[0] != min)
    {
        if (stack_a->data[stack_a->top] == min)
            stack_reverse_rotate(stack_a, true);
        else
            stack_rotate(stack_a, true);
    }
    if (is_sorted(stack_a))
        return ;
    stack_push_to(stack_a, stack_b, true);
    sort_three(stack_a);
    stack_push_to(stack_b, stack_a, true);
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int min;

    if (is_sorted(stack_a))
        return ;
    min = get_min(stack_a);
    while (stack_a->data[0] != min)
    {
        if (stack_a->data[stack_a->top] == min)
            stack_reverse_rotate(stack_a, true);
        else
            stack_rotate(stack_a, true);
    }
    if (is_sorted(stack_a))
        return ;
    stack_push_to(stack_a, stack_b, true);
    sort_four(stack_a, stack_b);
    stack_push_to(stack_b, stack_a, true);
}
