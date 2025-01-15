/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:29:28 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/14 18:23:10 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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
			if ((*s_b).data[j] < (*s_a).data[i]
				&& (*s_b).data[j] > best)
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
			if ((*s_a).data[j] > (*s_b).data[i]
				&& (*s_a).data[j] < best)
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

void	put_target_on_top_a(t_stack *s_a, t_stack *s_b,
		int c_i)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = (*s_a).top + 1;
	len_b = (*s_b).top + 1;
	if (c_i < len_a / 2)
		while (i++ < c_i)
			stack_rotate(s_a, true);
	else
		while (i++ < len_a - c_i)
			stack_reverse_rotate(s_a, true);
	i = 0;
	if (s_a->target[c_i] < len_b / 2)
		while (i++ < s_a->target[c_i])
			stack_rotate(s_b, true);
	else
		while (i++ < len_b - s_a->target[c_i])
			stack_reverse_rotate(s_b, true);
}

void	put_target_on_top_b(t_stack *s_b, t_stack *s_a,
		int c_i)
{
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = s_a->top + 1;
	len_b = s_b->top + 1;
	if (c_i < len_b / 2)
		while (i++ < c_i)
			stack_rotate(s_b, true);
	else
		while (i++ < len_b - c_i)
			stack_reverse_rotate(s_b, true);
	i = 0;
	if (s_b->target[c_i] < len_a / 2)
		while (i++ < s_b->target[c_i])
			stack_rotate(s_a, true);
	else
		while (i++ < len_a - s_b->target[c_i])
			stack_reverse_rotate(s_a, true);
}
