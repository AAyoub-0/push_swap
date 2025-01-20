/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:51 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 20:31:37 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	stack_print(t_stack *s)
{
	int	i;

	if (s->top == -1)
	{
		ft_printf("Stack[%p] { NULL }\n", s);
		return ;
	}
	i = 0;
	ft_printf("Stack[%p] { ", s);
	while (i <= s->top)
	{
		ft_printf("%d", s->data[i]);
		if (i < s->top)
			ft_printf(", ");
		i++;
	}
	ft_printf(" }\n");
}

t_bool is_valid_args(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t' && str[i] != '-' && str[i] != '+')
			return (false);
		if (str[i] == '-' || str[i] == '+')
		{
			if (!str[i + 1] || !ft_isdigit(str[i + 1]))
				return (false);
		}
		i++;
    }
    return (true);
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
		if (ft_isdigit(str[i]) || str[i] == '-')
        {
            num = ft_atoi_cursor(&str[i], &i, &error);
            if (!num && error)
            {
                ft_printf("Error\n");
                exit(stack_destroy(s));
            }
			stack_push(s, num);
        }
		i++;
	}
    free(str);
	return (s);
}

t_bool check_doubls(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->data[i] == stack->data[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
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
char	*join_args(int ac, char **av)
{
	int 	i;
	char 	*str;

	i = 1;
	str = ft_strdup(av[i]);
	if (!str)
		exit(1);
	while (++i < ac)
	{
		str = ft_strjoin_free(str, " ");
		str = ft_strjoin_free(str, av[i]);
	}
	return (str);
}

