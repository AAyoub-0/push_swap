/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:54:16 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/06 00:27:19 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void swap_if_needed(t_stack *stack)
{
    int *array;

    array = stack->data;
    if (array[0] > array[1])
        stack_swap(stack, TRUE);
}

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b, int median)
{
    int		i;
    int		smallest;
    int		smallest_index;

    smallest = INT_MAX;
    i = 0;
    while (i <= stack_a->top)
    {
        if (stack_a->data[i] < smallest && stack_a->data[i] <= median)
        {
            smallest = stack_a->data[i];
            smallest_index = i;
        }
        i++;
    }
    if (smallest_index < (stack_a->top + 1) / 2)
        while (stack_a->data[0] != smallest)
            stack_rotate(stack_a, TRUE);
    else
        while (stack_a->data[0] != smallest)
            stack_reverse_rotate(stack_a, TRUE);
    stack_push_to(stack_a, stack_b, TRUE);
    swap_if_needed(stack_b);
}

void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int    get_median(t_stack *stack)
{
    int		*array;
    int		median;
    int		i;
    int		j;

    array = stack->data;
    i = 0;
    while (i <= stack->top)
    {
        j = 0;
        while (j <= stack->top)
        {
            if (array[j] < array[i])
                ft_swap(&array[j], &array[i]);
            j++;
        }
        i++;
    }
    median = array[(stack->top + 1) / 2];
    return (median);
}

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
    int		i;
    int		median;

    i = 0;
    if (stack_b->top < 1)
        return ;
    while (stack_b->top >= 0)
    {
        median = get_median(stack_b);
        printf("median = %d\n", median);
        printf("stack_b->data[0] = %d\n", stack_b->data[0]);
        stack_print(stack_b);
        if (stack_b->data[0] <= median)
            stack_push_to(stack_b, stack_a, TRUE);
        else
        {
            if (stack_b->data[0] == stack_b->data[stack_b->top])
                stack_reverse_rotate(stack_b, TRUE);
            else
                stack_rotate(stack_b, TRUE);
        }
    }
}

void	median_sort(t_stack *stack_a, t_stack *stack_b)
{
    stack_print(stack_a);
    stack_print(stack_b);
    while (stack_a->top != 4)
        push_smallest_to_b(stack_a, stack_b, get_median(stack_a));
    stack_print(stack_a);
    stack_print(stack_b);
    sort_five(stack_a, stack_b);
    stack_print(stack_a);
    sort_b(stack_a, stack_b);
}
