/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:54:16 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/12 17:51:01 by aayoub           ###   ########.fr       */
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

void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	long best_target;

	i = 0;
	while (i <= (*stack_a).top)
	{
		j = 0;
		best_target = LONG_MIN;
		while (j <= (*stack_b).top)
		{
			if ((*stack_b).data[j] < (*stack_a).data[i] 
				&& (*stack_b).data[j] > best_target)
			{
				best_target = (*stack_b).data[j];
				(*stack_a).target[i] = j;
			}
			j++;
		}
		if (best_target == LONG_MIN)
			(*stack_a).target[i] = get_max_index(stack_b);
		i++;
	}
}

void	set_target_b(t_stack *stack_b, t_stack *stack_a)
{
	int i;
	int j;
	long best_target;

	i = 0;
	while (i <= (*stack_b).top)
	{
		j = 0;
		best_target = LONG_MAX;
		while (j <= (*stack_a).top)
		{
			if ((*stack_a).data[j] > (*stack_b).data[i] 
				&& (*stack_a).data[j] < best_target)
			{
				best_target = (*stack_a).data[j];
				(*stack_b).target[i] = j;
			}
			j++;
		}
		if (best_target == LONG_MAX)
			(*stack_b).target[i] = get_min_index(stack_a);
		i++;
	}
}

void	push_cheapest_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int len_a;
	int len_b;
	long cheapest;
	int push_cost;
	int cheapest_index;

	len_a = (*stack_a).top + 1;
	len_b = (*stack_b).top + 1;
	cheapest = LONG_MAX;
	cheapest_index = 0;
	i = 0;
	while (i < len_a)
	{
		push_cost = i;
		if (i > len_a / 2)
			push_cost = len_a - i;
		if (stack_a->target[i] <= len_b / 2)
			push_cost += stack_a->target[i];
		else
			push_cost += len_b - stack_a->target[i];
		if (push_cost < cheapest)
		{
			cheapest = push_cost;
			cheapest_index = i;
		}
		i++;
	}
	// i = 0;
	// // rotate both at the same time if needed
	// if (cheapest_index < len_a / 2 && stack_a->target[cheapest_index] < len_b / 2)
	// 	while (i++ < cheapest_index)
	// 		stack_rotate_both(stack_a, stack_b, true);
	// if (cheapest_index >= len_a / 2 && stack_a->target[cheapest_index] >= len_b / 2)
	// 	while (i++ < len_a - cheapest_index)
	// 		stack_reverse_rotate_both(stack_a, stack_b, true);
	i = 0;
	// rotate a and b if needed so the target and the cheapest are at the top
	if (cheapest_index < len_a / 2)
		while (i++ < cheapest_index)
			stack_rotate(stack_a, true);
	else
		while (i++ < len_a - cheapest_index)
			stack_reverse_rotate(stack_a, true);
	i = 0;
	if (stack_a->target[cheapest_index] < len_b / 2)
		while (i++ < stack_a->target[cheapest_index])
			stack_rotate(stack_b, true);
	else
		while (i++ < len_b - stack_a->target[cheapest_index])
			stack_reverse_rotate(stack_b, true);
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

	len_a = (*stack_a).top + 1;
	len_b = (*stack_b).top + 1;
	cheapest = LONG_MAX;
	cheapest_index = 0;
	i = 0;
	while (i < len_b)
	{
		push_cost = i;
		if (i > len_b / 2)
			push_cost = len_b - i;
		if (stack_b->target[i] <= len_a / 2)
			push_cost += stack_b->target[i];
		else
			push_cost += len_a - stack_b->target[i];
		if (push_cost < cheapest)
		{
			cheapest = push_cost;
			cheapest_index = i;
		}
		i++;
	}
	// i = 0;
	// // rotate both at the same time if needed
	// if (cheapest_index <= len_b / 2 && stack_b->target[cheapest_index] <= len_a / 2)
	// 	while (i++ < cheapest_index)
	// 		stack_rotate_both(stack_a, stack_b, true);
	// if (cheapest_index > len_b / 2 && stack_b->target[cheapest_index] > len_a / 2)
	// 	while (i++ < len_b - cheapest_index)
	// 		stack_reverse_rotate_both(stack_a, stack_b, true);
	i = 0;
	// rotate a and b if needed so the target and the cheapest are at the top
	if (cheapest_index < len_b / 2)
		while (i++ < cheapest_index)
			stack_rotate(stack_b, true);
	else
		while (i++ < len_b - cheapest_index)
			stack_reverse_rotate(stack_b, true);
	i = 0;
	if (stack_b->target[cheapest_index] < len_a / 2)
		while (i++ < stack_b->target[cheapest_index])
			stack_rotate(stack_a, true);
	else
		while (i++ < len_a - stack_b->target[cheapest_index])
			stack_reverse_rotate(stack_a, true);
	stack_push_to(stack_b, stack_a, true);
}

// fucntion that moves the min value to the top of the stack
void	move_min_to_top(t_stack *stack)
{
	int min_index;
	int len;
	int i;

	len = (*stack).top + 1;
	min_index = get_min_index(stack);
	i = 0;
	if (min_index < len / 2)
		while (i++ < min_index)
			stack_rotate(stack, true);
	else
		while (i++ < len - min_index)
			stack_reverse_rotate(stack, true);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	size_a = (*stack_a).size;
	if (size_a-- > 5 && !is_sorted(stack_a))
		stack_push_to(stack_a, stack_b, true);
	if (size_a-- > 5 && !is_sorted(stack_a))
		stack_push_to(stack_a, stack_b, true);
	while (size_a-- > 5 && !is_sorted(stack_a))
	{
		set_target_a(stack_a, stack_b);
		push_cheapest_a(stack_a, stack_b);
	}
	sort_five(stack_a, stack_b);
	while ((*stack_b).top >= 0)
	{
		set_target_b(stack_b, stack_a);
		push_cheapest_b(stack_a, stack_b);
	}
	move_min_to_top(stack_a);
}