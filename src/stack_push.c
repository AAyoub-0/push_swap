/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:46 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 23:41:02 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_push(t_stack *s, int value)
{
	if (s->top == s->size - 1)
		return ;
	s->data[++s->top] = value;
}

void	stack_push_first(t_stack *s, int value)
{
	int	i;

	i = s->top;
	while (i >= 0)
	{
		s->data[i + 1] = s->data[i];
		i--;
	}
	s->data[0] = value;
	s->top++;
}

void	stack_push_array(t_stack *s, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		s->data[i] = array[i];
		s->top++;
		i++;
	}
}
void	stack_push_to(t_stack *s_from, t_stack *s_to, t_bool print)
{
	if (s_from->top == -1)
		return ;
	if (s_to->top == s_to->size - 1)
		return ;
	stack_push_first(s_to, s_from->data[0]);
	stack_delete(s_from, 0);
	if (print)
		printf("p%c\n", s_to->name[0]);
}