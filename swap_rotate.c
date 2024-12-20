/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:58 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/20 16:14:59 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	stack_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = tmp;
}

void	stack_reverse_rotate(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->top < 1)
		return ;
	tmp = stack->data[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}