/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:55 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/23 17:44:50 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_stack	*stack_create(int size, char name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->data = malloc(size * sizeof(int));
	stack->name = ft_calloc(2, sizeof(char));
	stack->name[0] = name;
	stack->top = -1;
	stack->size = size;
	return (stack);
}

void	stack_pop(t_stack *stack)
{
	if (stack->top == -1)
		return ;
	stack->top--;
}

void	stack_delete(t_stack *stack, int index)
{
	int	i;

	if (index < 0 || index > stack->top)
		return ;
	i = index;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->top--;
}

void	stack_destroy(t_stack *stack)
{
	free(stack->data);
	free(stack);
}
