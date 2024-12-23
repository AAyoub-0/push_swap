/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:49 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/23 17:44:43 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_swap(t_stack *stack, t_bool print)
{
	int tmp;
	if (stack->top < 1)
		return ;
	tmp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = tmp;
	if (print)
		printf("s%c\n", stack->name[0]);
}

void	stack_swap_both(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	stack_swap(stack_a, 0);
	stack_swap(stack_b, 0);
	if (print)
		printf("ss\n");
}