/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/29 16:02:58 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(1);
	str = join_args(ac, av);
	if (!str)
		return (ft_putstr_fd(ERROR, 2), EXIT_FAILURE);
	if (!is_valid_args(str))
		return (ft_putstr_fd(ERROR, 2), free(str), EXIT_FAILURE);
	a = stack_create_from_str(str, 'a');
	if (!a)
		return (ft_putstr_fd(ERROR, 2), EXIT_FAILURE);
	if (!check_doubls(a))
		return (ft_putstr_fd(ERROR, 2), stack_destroy(a), EXIT_FAILURE);
	b = stack_create(a->size, 'b');
	if (!b)
		return (ft_putstr_fd(ERROR, 2), EXIT_FAILURE);
	sort(a, b);
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}
