/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:33 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/23 17:44:30 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    sort_two(t_stack *stack)
{
    if (stack->data[0] > stack->data[1])
        stack_swap(stack, 1);
}

void    sort_three(t_stack *stack)
{
    if (stack->data[0] > stack->data[1] && stack->data[1] > stack->data[2])
    {
        stack_swap(stack, 1);
        stack_rotate(stack, 1);
    }
}