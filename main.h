/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:55 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/20 16:38:11 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*data;
	int	top;
	int	size;
}		t_stack;

t_stack	*stack_create(int size);
void	stack_pop(t_stack *stack);
void	stack_delete(t_stack *stack, int index);
void	stack_destroy(t_stack *stack);

void	stack_print(t_stack *stack);
void	stack_create_from_char(t_stack *stack, char *str);
int		stack_str_size(char *str);

void	swap_stack(t_stack *stack);

void	stack_push(t_stack *stack, int value);
void	stack_push_to(t_stack *stack_from, t_stack *stack_to);

void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);

void    sort_two(t_stack *stack);
void    sort_three(t_stack *stack);

#endif