/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:29:28 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/28 17:47:33 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_target_a(t_stack *s_a, t_stack *s_b)
{
	int		i;
	int		j;
	long	best;

	i = 0;
	while (i <= (*s_a).top)
	{
		j = 0;
		best = LONG_MIN;
		while (j <= (*s_b).top)
		{
			if ((*s_b).data[j] < (*s_a).data[i] && (*s_b).data[j] > best)
			{
				best = (*s_b).data[j];
				(*s_a).target[i] = j;
			}
			j++;
		}
		if (best == LONG_MIN)
			(*s_a).target[i] = get_max_index(s_b);
		i++;
	}
}

void	set_target_b(t_stack *s_b, t_stack *s_a)
{
	int		i;
	int		j;
	long	best;

	i = 0;
	while (i <= (*s_b).top)
	{
		j = 0;
		best = LONG_MAX;
		while (j <= (*s_a).top)
		{
			if ((*s_a).data[j] > (*s_b).data[i] && (*s_a).data[j] < best)
			{
				best = (*s_a).data[j];
				(*s_b).target[i] = j;
			}
			j++;
		}
		if (best == LONG_MAX)
			(*s_b).target[i] = get_min_index(s_a);
		i++;
	}
}

void	rotate_one(t_stack *s, int s_i)
{
	int	i;
	int	len;

	i = 0;
	len = s->top + 1;
	if (s_i < len / 2)
		while (i++ < s_i)
			stack_rotate(s, true);
	else
		while (i++ < len - s_i)
			stack_reverse_rotate(s, true);
}

void	put_target_on_top(t_stack *a, t_stack *b, int c_i, int t_i)
{
	int	len_a;
	int	len_b;

	len_a = a->top + 1;
	len_b = b->top + 1;
	while (c_i < len_a / 2 && c_i > 0 && t_i < len_b / 2 && t_i > 0)
	{
		stack_rotate_both(a, b, true);
		c_i--;
		t_i--;
	}
	while (c_i >= len_a / 2 && c_i < len_a && t_i >= len_b / 2 && t_i < len_b)
	{
		stack_reverse_rotate_both(a, b, true);
		c_i++;
		t_i++;
	}
	rotate_one(a, c_i);
	rotate_one(b, t_i);
}
