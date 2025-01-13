/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:35:15 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/13 16:36:37 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	get_max_index(t_stack *stack)
{
	int i;
	int max;
	int index;

	i = 0;
	max = INT_MIN;
	index = 0;
	while (i <= (*stack).top)
	{
		if ((*stack).data[i] > max)
		{
			max = (*stack).data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int get_min_index(t_stack *stack)
{
	int i;
	int min;
	int index;

	i = 0;
	min = INT_MAX;
	index = 0;
	while (i <= (*stack).top)
	{
		if ((*stack).data[i] < min)
		{
			min = (*stack).data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int     get_cheapest_index(t_stack *stack, int o_stack_len)
{
	int i;
    long cheapest;
	int cheapest_index;
    int push_cost;

    i = 0;
    cheapest = LONG_MAX;
    cheapest_index = 0;
    while (i < (stack->top + 1))
	{
		push_cost = i;
		if (i > (stack->top + 1) / 2)
			push_cost = (stack->top + 1) - i;
		if (stack->target[i] <= o_stack_len / 2)
			push_cost += stack->target[i];
		else
			push_cost += o_stack_len - stack->target[i];
		if (push_cost < cheapest)
		{
			cheapest = push_cost;
			cheapest_index = i;
		}
		i++;
	}
    return (cheapest_index);
}

void	push_cheapest_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int len_a;
	int len_b;
	int push_cost;
	int cheapest_index;

	len_a = stack_a->top + 1;
	len_b = stack_b->top + 1;
    cheapest_index = get_cheapest_index(stack_a, len_b);
	// i = 0;
	// if (cheapest_index < len_a / 2 && stack_a->target[cheapest_index] < len_b / 2)
	// 	while (i++ < cheapest_index)
	// 		stack_rotate_both(stack_a, stack_b, true);
	// if (cheapest_index >= len_a / 2 && stack_a->target[cheapest_index] >= len_b / 2)
	// 	while (i++ < len_a - cheapest_index)
	// 		stack_reverse_rotate_both(stack_a, stack_b, true);
    // cheapest_index -= i;
    put_target_on_top_a(stack_a, stack_b, cheapest_index);
	stack_push_to(stack_a, stack_b, true);
}

void	push_cheapest_b(t_stack *stack_b, t_stack *stack_a)
{
	int i;
	int len_a;
	int len_b;
	long cheapest;
	int push_cost;
	int cheapest_index;

	len_a = stack_a->top + 1;
	len_b = stack_b->top + 1;
    cheapest_index = get_cheapest_index(stack_b, len_a);
	// i = 0;
	// if (cheapest_index < len_b / 2 && stack_b->target[cheapest_index] < len_a / 2)
	// 	while (i++ < cheapest_index)
	// 		stack_rotate_both(stack_a, stack_b, true);
	// if (cheapest_index >= len_b / 2 && stack_b->target[cheapest_index] >= len_a / 2)
	// 	while (i++ < len_b - cheapest_index)
	// 		stack_reverse_rotate_both(stack_a, stack_b, true);
    // cheapest_index -= i;
    put_target_on_top_b(stack_b, stack_a, cheapest_index);
	stack_push_to(stack_b, stack_a, true);
}
