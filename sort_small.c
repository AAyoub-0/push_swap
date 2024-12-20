/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:33 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/20 16:34:13 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    sort_two(t_stack *stack)
{
    if (stack->data[0] > stack->data[1])
        swap_stack(stack);
}

void    sort_three(t_stack *stack)
{
    if (stack->data[0] > stack->data[1] && stack->data[1] > stack->data[2])
    {
        swap_stack(stack);
        stack_rotate(stack);
    }
}