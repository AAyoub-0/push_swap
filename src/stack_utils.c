/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:51 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/13 17:56:01 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_print(t_stack *s)
{
	int	i;

	if (s->top == -1)
	{
		printf("s[%p] { NULL }\n", s);
		return ;
	}
	i = 0;
	printf("Stack[%p] { ", s);
	while (i <= s->top)
	{
		printf("%d", s->data[i]);
		if (i < s->top)
			printf(", ");
		i++;
	}
	printf(" }\n");
}

void	print_array(int *array, int size)
{
	int	i;

	if (size == 0)
	{
		printf("Array[%p] { NULL }\n", array);
		return ;
	}
	i = 0;
	printf("Array[%p] { ", array);
	while (i < size)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf(" }\n");
}

t_stack	*stack_create_from_str(char *str, char name)
{
	int		i;
	int		sign;
	t_stack	*s;

	i = 0;
	sign = 1;
	s = stack_create(stack_str_size(str), name);
	while (str[i])
	{
		if (str[i] == '-')
			sign = -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			stack_push(s, (str[i] - '0') * sign);
			i++;
		}
		sign = 1;
		i++;
	}
	return (s);
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
