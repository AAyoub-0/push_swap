/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:46 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/23 17:44:37 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_push(t_stack *stack, int value)
{
	if (stack->top == stack->size - 1)
		return ;
	stack->data[++stack->top] = value;
}

void	stack_push_to(t_stack *stack_from, t_stack *stack_to, t_bool print)
{
	if (stack_from->top == -1)
		return ;
	if (stack_to->top == stack_to->size - 1)
		return ;
	stack_push(stack_to, stack_from->data[0]);
	stack_delete(stack_from, 0);
	if (print)
		printf("p%c\n", stack_to->name[0]);
}