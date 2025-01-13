/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:54:16 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/13 16:43:11 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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
		push_cheapest_b(stack_b, stack_a);
	}
	move_min_to_top(stack_a);
}
