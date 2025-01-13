/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:29:28 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/13 16:55:23 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	long	best_target;

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
	int		i;
	int		j;
	long	best_target;

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

void	put_target_on_top_a(t_stack *stack_a, t_stack *stack_b,
		int cheapest_index)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = (*stack_a).top + 1;
	len_b = (*stack_b).top + 1;
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
}

void	put_target_on_top_b(t_stack *stack_b, t_stack *stack_a,
		int cheapest_index)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = stack_a->top + 1;
	len_b = stack_b->top + 1;
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
}
