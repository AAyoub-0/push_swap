/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:58 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/13 16:51:57 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_rotate(t_stack *stack, t_bool print)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i <= stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = tmp;
	if (print)
		printf("r%c\n", stack->name[0]);
}

void	stack_reverse_rotate(t_stack *stack, t_bool print)
{
	int	tmp;
	int	i;

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
	if (print)
		printf("rr%c\n", stack->name[0]);
}

void	stack_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	stack_rotate(stack_a, 0);
	stack_rotate(stack_b, 0);
	if (print)
		printf("rr\n");
}

void	stack_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b,
		t_bool print)
{
	stack_reverse_rotate(stack_a, 0);
	stack_reverse_rotate(stack_b, 0);
	if (print)
		printf("rrr\n");
}