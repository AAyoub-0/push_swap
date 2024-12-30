/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:45:38 by aayoub            #+#    #+#             */
/*   Updated: 2024/12/30 02:50:44 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_bool  is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->data[i] > stack->data[i + 1])
            return (FALSE);
        i++;
    }
    return (TRUE);
}

t_bool  is_sorted_desc(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->data[i] < stack->data[i + 1])
            return (FALSE);
        i++;
    }
    return (TRUE);
}

void    sort(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return ;
    if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size == 4)
        sort_four(stack_a, stack_b);
    else if (stack_a->size == 5)
        sort_five(stack_a, stack_b);
    return ;
}