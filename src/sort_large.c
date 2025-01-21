/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:54:16 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/21 13:20:03 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_min_to_top(t_stack *s)
{
	int	min_index;
	int	len;
	int	i;

	len = (*s).top + 1;
	min_index = get_min_index(s);
	i = 0;
	if (min_index < len / 2)
		while (i++ < min_index)
			stack_rotate(s, true);
	else
		while (i++ < len - min_index)
			stack_reverse_rotate(s, true);
}

void	sort_large(t_stack *s_a, t_stack *s_b)
{
	int	size_a;

	size_a = (*s_a).top + 1;
	if (size_a-- > 5 && !is_sorted(s_a))
		stack_push_to(s_a, s_b, true);
	if (size_a-- > 5 && !is_sorted(s_a))
		stack_push_to(s_a, s_b, true);
	while (size_a-- > 5 && !is_sorted(s_a))
	{
		set_target_a(s_a, s_b);
		push_cheapest_a(s_a, s_b);
	}
	sort_five(s_a, s_b);
	while ((*s_b).top >= 0)
	{
		set_target_b(s_b, s_a);
		push_cheapest_b(s_b, s_a);
	}
	move_min_to_top(s_a);
}
