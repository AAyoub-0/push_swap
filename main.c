/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/14 20:57:50 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	// tab of three
	// size_3_test();
	// tab of four
	// size_4_test();
	// tab of five
	// size_5_test();
	// tab of 100
	// size_100_test();
	// test_targets();
    // printf("size : %d\n", stack_str_size("-10 2 +3 45 -78 9 6"));
    t_stack *stack = stack_create_from_str("5645612316543551354 2 +3 45 -78 9 6", 'a');
    stack_reverse_rotate(stack, true);
    stack_reverse_rotate(stack, true);
    stack_print(stack);
	return (0);
}