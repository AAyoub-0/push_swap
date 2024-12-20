/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:46 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/20 16:14:47 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	stack_push(t_stack *stack, int value)
{
	if (stack->top == stack->size - 1)
		return ;
	stack->data[++stack->top] = value;
}

void	stack_push_to(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top == -1)
		return ;
	if (stack_to->top == stack_to->size - 1)
		return ;
	stack_push(stack_to, stack_from->data[0]);
	stack_delete(stack_from, 0);
}