/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:51 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/15 12:03:28 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_print(t_stack *s)
{
	int	i;

	if (s->top == -1)
	{
		printf("Stack[%p] { NULL }\n", s);
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

int is_valid_args(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
    }
    return 0;
}

t_stack	*stack_create_from_str(char *str, char name)
{
	int		i;
    int     error;
    int     num;
	t_stack	*s;

	i = 0;
    error = 0;
	s = stack_create(stack_str_size(str), name);
	while (str[i])
	{
		while (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
        {
            num = ft_atoi_cursor(&str[i], &i, &error);
            if (!num && !error)
            {
                printf("Error\n");
                exit(stack_destroy(s));
            }
			stack_push(s, num);
        }
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
		while (ft_isdigit(str[i]))
        {
            i++;
			j++;
        }
		if (j)
			size++;
		i++;
	}
	return (size);
}
