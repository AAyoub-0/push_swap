/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/29 11:45:21 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (!stack || !stack->data || !stack->target || !stack->name)
		return (stack_destroy(stack), NULL);
	return (stack);
}

t_stack	*stack_create_from_str(char *str, char name)
{
	int		i;
	int		error;
	int		num;
	t_stack	*s;

	i = 0;
	error = 0;
	s = stack_create(stack_str_size(str), name);
	if (!s)
		return (free(str), NULL);
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			num = ft_atoi_cursor(&str[i], &i, &error);
			if (!num && error)
				return (free(str), stack_destroy(s), NULL);
			stack_push(s, num);
		}
		if (str[i])
			i++;
	}
	free(str);
	return (s);
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
	if (s->data)
		free(s->data);
	if (s->name)
		free(s->name);
	if (s->target)
		free(s->target);
	if (s)
		free(s);
	return (0);
}
