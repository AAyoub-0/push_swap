/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:35:15 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/26 21:29:41 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_index(t_stack *s)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = INT_MIN;
	index = 0;
	while (i <= (*s).top)
	{
		if ((*s).data[i] > max)
		{
			max = (*s).data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_min_index(t_stack *s)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = INT_MAX;
	index = 0;
	while (i <= (*s).top)
	{
		if ((*s).data[i] < min)
		{
			min = (*s).data[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_cheapest_index(t_stack *s, int o_s_len)
{
	int		i;
	int		c_i;
	long	cheapest;
	int		push_cost;

	i = 0;
	cheapest = LONG_MAX;
	c_i = 0;
	while (i < (s->top + 1))
	{
		push_cost = i;
		if (i > (s->top + 1) / 2)
			push_cost = (s->top + 1) - i;
		if (s->target[i] <= o_s_len / 2)
			push_cost += s->target[i];
		else
			push_cost += o_s_len - s->target[i];
		if (push_cost < cheapest)
		{
			cheapest = push_cost;
			c_i = i;
		}
		i++;
	}
	return (c_i);
}

void	push_cheapest_a(t_stack *s_a, t_stack *s_b)
{
	int	len_b;
	int	c_i;
	
	len_b = s_b->top + 1;
	c_i = get_cheapest_index(s_a, len_b);
	put_target_on_top(s_a, s_b, c_i, s_a->target[c_i]);
	stack_push_to(s_a, s_b, true);
}

void	push_cheapest_b(t_stack *s_b, t_stack *s_a)
{
	int	len_a;
	int	c_i;

	len_a = s_a->top + 1;
	c_i = get_cheapest_index(s_b, len_a);
	put_target_on_top(s_b, s_a, c_i, s_b->target[c_i]);
	stack_push_to(s_b, s_a, true);
}
