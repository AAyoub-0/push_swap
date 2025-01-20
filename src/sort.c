/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:45:38 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/20 23:41:02 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->data[i] > s->data[i + 1])
			return (false);
		i++;
	}
	return (true);
}

t_bool	is_sorted_desc(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->data[i] < s->data[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	if (is_sorted(s_a))
		return ;
	if (s_a->size == 2)
		sort_two(s_a);
	else if (s_a->size == 3)
		sort_three(s_a);
	else if (s_a->size == 4)
		sort_four(s_a, s_b);
	else if (s_a->size == 5)
		sort_five(s_a, s_b);
	else
		sort_large(s_a, s_b);
	return ;
}