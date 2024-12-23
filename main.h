/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:55 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/23 16:41:57 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	char *name;
	int	*data;
	int	top;
	int	size;
}		t_stack;

typedef unsigned char t_bool;

t_stack	*stack_create(int size, char name);
void	stack_pop(t_stack *stack);
void	stack_delete(t_stack *stack, int index);
void	stack_destroy(t_stack *stack);

void	stack_print(t_stack *stack);
t_stack	*stack_create_from_str(char *str, char name);
int		stack_str_size(char *str);

/*		 ----------------------------- Stack operations -----------------------------		 */
void	stack_swap(t_stack *stack, t_bool print);
void	stack_swap_both(t_stack *stack_a, t_stack *stack_b, t_bool print);

void	stack_push(t_stack *stack, int value);
void	stack_push_to(t_stack *stack_from, t_stack *stack_to, t_bool print);

void	stack_rotate(t_stack *stack, t_bool print);
void	stack_reverse_rotate(t_stack *stack, t_bool print);
void	stack_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);
void	stack_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);
/*		 ---------------------------------------------------------------------------		 */

void    sort_two(t_stack *stack);
void    sort_three(t_stack *stack);

#endif