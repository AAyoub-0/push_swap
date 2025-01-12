/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:46 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/12 01:34:59 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_push(t_stack *stack, int value)
{
	if (stack->top == stack->size - 1)
		return ;
	stack->data[++stack->top] = value;
}

void	stack_push_first(t_stack *stack, int value)
{
	int i;

	i = stack->top;
	while (i >= 0)
	{
		stack->data[i + 1] = stack->data[i];
		i--;
	}
	stack->data[0] = value;
	stack->top++;
}

void	stack_push_array(t_stack *stack, int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		stack->data[i] = array[i];
		stack->top++;
		i++;
	}
}
void	stack_push_to(t_stack *stack_from, t_stack *stack_to, t_bool print)
{
	if (stack_from->top == -1)
		return ;
	if (stack_to->top == stack_to->size - 1)
		return ;
	stack_push_first(stack_to, stack_from->data[0]);
	stack_delete(stack_from, 0);
	if (print)
		printf("p%c\n", stack_to->name[0]);
}