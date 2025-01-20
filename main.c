/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 17:27:27 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	char	*str;
	if (ac < 2)
		return (1);
	str = join_args(ac, av);
	if (!is_valid_args(str))
	{
		ft_printf("Error\n");
		return (free(str), 1);
	}
    t_stack *a = stack_create_from_str(str, 'a');
	if (!check_doubls(a))
	{
		ft_printf("Error\n");
		return (stack_destroy(a), 1);
	}
	t_stack *b = stack_create(a->size, 'b');
	sort(a, b);
    stack_print(a);
    stack_destroy(a);
    stack_destroy(b);
	return (0);
}
