/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:33 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 23:41:02 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *s)
{
	if (s->data[0] > s->data[1])
		stack_swap(s, true);
}

void	sort_three(t_stack *s)
{
	if (is_sorted(s))
		return ;
	if (is_sorted_desc(s))
	{
		stack_rotate(s, true);
		stack_swap(s, true);
	}
	else if (s->data[0] > s->data[1] && s->data[0] > s->data[2])
		stack_rotate(s, true);
	else if (s->data[0] < s->data[1] && s->data[0] > s->data[2])
		stack_reverse_rotate(s, true);
	else if (s->data[0] < s->data[1] && s->data[1] > s->data[2])
	{
		stack_reverse_rotate(s, true);
		stack_swap(s, true);
	}
	else
		stack_swap(s, true);
}

int	get_min(t_stack *s)
{
	int	i;
	int	min;

	i = 0;
	min = s->data[0];
	while (i <= s->top)
	{
		if (s->data[i] < min)
			min = s->data[i];
		i++;
	}
	return (min);
}

void	sort_four(t_stack *s_a, t_stack *s_b)
{
	int	min;

	if (is_sorted(s_a))
		return ;
	min = get_min(s_a);
	while (s_a->data[0] != min)
	{
		if (s_a->data[s_a->top] == min)
			stack_reverse_rotate(s_a, true);
		else
			stack_rotate(s_a, true);
	}
	if (is_sorted(s_a))
		return ;
	stack_push_to(s_a, s_b, true);
	sort_three(s_a);
	stack_push_to(s_b, s_a, true);
}

void	sort_five(t_stack *s_a, t_stack *s_b)
{
	int	min;

	if (is_sorted(s_a))
		return ;
	min = get_min(s_a);
	while (s_a->data[0] != min)
	{
		if (s_a->data[s_a->top] == min)
			stack_reverse_rotate(s_a, true);
		else
			stack_rotate(s_a, true);
	}
	if (is_sorted(s_a))
		return ;
	stack_push_to(s_a, s_b, true);
	sort_four(s_a, s_b);
	stack_push_to(s_b, s_a, true);
}
