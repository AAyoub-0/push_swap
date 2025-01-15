/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/15 11:56:48 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_stack	*stack_create(int size, char name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->data = malloc(size * sizeof(int));
	stack->target = malloc(size * sizeof(int));
	stack->name = ft_calloc(2, sizeof(char));
	stack->name[0] = name;
	stack->top = -1;
	stack->size = size;
	return (stack);
}

void	stack_pop(t_stack *s)
{
	if (s->top == -1)
		return ;
	s->top--;
}

void	stack_delete(t_stack *s, int index)
{
	int	i;

	if (index < 0 || index > s->top)
		return ;
	i = index;
	while (i < s->top)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->top--;
}

int	stack_destroy(t_stack *s)
{
	free(s->data);
	free(s->name);
    free(s->target);
	free(s);
    return (0);
}
