/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:41 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 23:41:02 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_str_check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
		{
			printf("Error\n");
			exit(1);
		}
		if (str[i] < '0' || str[i] > '9' || str[i] == ' ' || str[i] == '-')
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	stack_str_check_duplicates(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	stack_str_check_int_overflow(char *str)
{
	int i;
	int j;
	int sign;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		j = i;
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		if (j - i > 10)
		{
			printf("Error\n");
			exit(1);
		}
		if (j - i == 10)
		{
			if (sign == 1 && ft_strncmp("2147483647", str + i, 10) < 0)
			{
				printf("Error\n");
				exit(1);
			}
			if (sign == -1 && ft_strncmp("-2147483648", str + i, 11) < 0)
			{
				printf("Error\n");
				exit(1);
			}
		}
		i = j + 1;
	}
}