/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:58 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/13 17:56:51 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_rotate(t_stack *s, t_bool print)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->data[0];
	i = 0;
	while (i <= s->top)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->top] = tmp;
	if (print)
		printf("r%c\n", s->name[0]);
}

void	stack_reverse_rotate(t_stack *s, t_bool print)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->data[s->top];
	i = s->top;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = tmp;
	if (print)
		printf("rr%c\n", s->name[0]);
}

void	stack_rotate_both(t_stack *s_a, t_stack *s_b, t_bool print)
{
	stack_rotate(s_a, 0);
	stack_rotate(s_b, 0);
	if (print)
		printf("rr\n");
}

void	stack_reverse_rotate_both(t_stack *s_a, t_stack *s_b,
		t_bool print)
{
	stack_reverse_rotate(s_a, 0);
	stack_reverse_rotate(s_b, 0);
	if (print)
		printf("rrr\n");
}