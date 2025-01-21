/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/21 17:10:09 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(1);
	str = join_args(ac, av);
	if (!is_valid_args(str))
	{
		ft_printf("Error\n");
		exit(1);
	}
	a = stack_create_from_str(str, 'a');
	if (!check_doubls(a))
	{
		ft_printf("Error\n");
		exit(stack_destroy(a));
	}
	b = stack_create(a->size, 'b');
	sort(a, b);
    stack_print(a);
	return (0);
}
