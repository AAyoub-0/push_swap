/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/29 15:42:10 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define QUIT "q"
# define OK   "OK"
# define KO   "KO"
# define ERROR "Error\n"

# define PA   "pa"
# define PB   "pb"
# define SS   "ss"
# define SA   "sa"
# define SB   "sb"
# define RR   "rr"
# define RA   "ra"
# define RB   "rb"
# define RRR  "rrr"
# define RRA  "rra"
# define RRB  "rrb"

typedef struct s_stack
{
	char	*name;
	int		*data;
	int		*target;
	int		top;
	int		size;
}			t_stack;

t_stack		*stack_create(int size, char name);
void		stack_pop(t_stack *stack);
void		stack_delete(t_stack *stack, int index);
int			stack_destroy(t_stack *stack);

t_bool		is_valid_args(char *str);
t_bool		check_doubls(t_stack *stack);
void		stack_print(t_stack *stack);
t_stack		*stack_create_from_str(char *str, char name);
char		*join_args(int ac, char **av);
int			stack_str_size(char *str);

void		stack_swap(t_stack *stack, t_bool print);
void		stack_swap_both(t_stack *stack_a, t_stack *stack_b, t_bool print);

void		stack_push(t_stack *stack, int value);
void		stack_push_first(t_stack *s, int value);
void		stack_push_array(t_stack *stack, int *array, int size);
void		stack_push_to(t_stack *stack_from, t_stack *stack_to, t_bool print);

void		stack_rotate(t_stack *stack, t_bool print);
void		stack_reverse_rotate(t_stack *stack, t_bool print);
void		stack_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);
void		stack_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b,
				t_bool print);

t_bool		is_sorted(t_stack *stack);
t_bool		is_sorted_desc(t_stack *stack);
void		sort(t_stack *stack_a, t_stack *stack_b);

void		sort_two(t_stack *stack);
void		sort_three(t_stack *stack);
void		sort_four(t_stack *stack_a, t_stack *stack_b);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		sort_large(t_stack *stack_a, t_stack *stack_b);

void		set_target_a(t_stack *stack_a, t_stack *stack_b);
void		set_target_b(t_stack *stack_b, t_stack *stack_a);
void		put_target_on_top_a(t_stack *stack_a, t_stack *stack_b,
				int cheapest_index);
void		put_target_on_top_b(t_stack *stack_b, t_stack *stack_a,
				int cheapest_index);
void		put_target_on_top(t_stack *a, t_stack *b, int c_i, int t_i);

int			get_max_index(t_stack *stack);
int			get_min_index(t_stack *stack);
int			get_cheapest_index(t_stack *stack, int o_stack_len);
void		push_cheapest_a(t_stack *stack_a, t_stack *stack_b);
void		push_cheapest_b(t_stack *stack_b, t_stack *stack_a);

#endif