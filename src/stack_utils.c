/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:51 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/06 15:25:01 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_print(t_stack *stack)
{
	int	i;

	if (stack->top == -1)
	{
		printf("Stack[%p] { NULL }\n", stack);
		return ;
	}
	i = 0;
	printf("Stack[%p] { ", stack);
	while (i <= stack->top)
	{
		printf("%d", stack->data[i]);
		if (i < stack->top)
			printf(", ");
		i++;
	}
	printf(" }\n");
}

t_stack	*stack_create_from_str(char *str, char name)
{
	int		i;
	int		sign;
	t_stack	*stack;

	i = 0;
	sign = 1;
	stack = stack_create(stack_str_size(str), name);
	while (str[i])
	{
		if (str[i] == '-')
			sign = -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			stack_push(stack, (str[i] - '0') * sign);
			i++;
		}
		sign = 1;
		i++;
	}
	return (stack);
}

int	stack_str_size(char *str)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		if (j)
			size++;
		i++;
	}
	return (size);
}
