/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:49 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/21 13:22:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_swap(t_stack *s, t_bool print)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
	if (print)
		printf("s%c\n", s->name[0]);
}

void	stack_swap_both(t_stack *s_a, t_stack *s_p, t_bool print)
{
	stack_swap(s_a, 0);
	stack_swap(s_p, 0);
	if (print)
		printf("ss\n");
}
