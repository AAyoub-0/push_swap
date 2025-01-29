/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/29 16:06:37 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_cmd(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, PA))
		stack_push_to(b, a, false);
	else if (ft_strcmp(line, PB))
		stack_push_to(a, b, false);
	else if (ft_strcmp(line, SA))
		stack_swap(a, false);
	else if (ft_strcmp(line, SB))
		stack_swap(b, false);
	else if (ft_strcmp(line, SS))
		stack_swap_both(a, b, false);
	else if (ft_strcmp(line, RA))
		stack_rotate(a, false);
	else if (ft_strcmp(line, RB))
		stack_rotate(b, false);
	else if (ft_strcmp(line, RR))
		stack_rotate_both(a, b, false);
	else if (ft_strcmp(line, RRA))
		stack_reverse_rotate(a, false);
	else if (ft_strcmp(line, RRB))
		stack_reverse_rotate(b, false);
	else if (ft_strcmp(line, RRR))
		stack_reverse_rotate_both(a, b, false);
	else
		return (0);
	return (1);
}

void	listen_cmd(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) >= 0 && *line != '\0')
	{
		if (ft_strcmp(line, QUIT))
			break ;
		if (stack_cmd(a, b, line))
		{
			stack_print(a);
			stack_print(b);
		}
		else
			return (free(line), ft_putstr_fd(ERROR, 2));
		if (is_sorted(a) && b->top == -1)
		{
			ft_putendl_fd(OK, 1);
			return ;
		}
		free(line);
	}
	ft_putendl_fd(KO, 1);
	return ;
}

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
	listen_cmd(a, b);
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}
