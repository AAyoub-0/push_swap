/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:13:55 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/12 02:05:01 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack
{
	char *name;
	int	*data;
	int *target;
	int	top;
	int	size;
}		t_stack;

typedef enum e_bool
{
	false = 0,
	true = 1
}		t_bool;

t_stack	*stack_create(int size, char name);
void	stack_pop(t_stack *stack);
void	stack_delete(t_stack *stack, int index);
void	stack_destroy(t_stack *stack);

void	stack_print(t_stack *stack);
void	print_array(int *array, int size);
t_stack	*stack_create_from_str(char *str, char name);
int		stack_str_size(char *str);

/*		 ----------------------------- Stack operations -----------------------------		 */
void	stack_swap(t_stack *stack, t_bool print);
void	stack_swap_both(t_stack *stack_a, t_stack *stack_b, t_bool print);

void	stack_push(t_stack *stack, int value);
void	stack_push_array(t_stack *stack, int *array, int size);
void	stack_push_to(t_stack *stack_from, t_stack *stack_to, t_bool print);

void	stack_rotate(t_stack *stack, t_bool print);
void	stack_reverse_rotate(t_stack *stack, t_bool print);
void	stack_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);
void	stack_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);
/*		 ---------------------------------------------------------------------------		 */

t_bool  is_sorted(t_stack *stack);
t_bool  is_sorted_desc(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);

void    sort_two(t_stack *stack);
void    sort_three(t_stack *stack);
void    sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

void	push_cheapest_a(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);
void	set_target_a(t_stack *stack_a, t_stack *stack_b);
void	set_target_b(t_stack *stack_b, t_stack *stack_a);

void    sort_test(char *test, int size, int *array);
void    size_4_test();
void    size_3_test();
void    size_5_test();
void    size_100_test();
void    test_targets();

#endif