/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:49 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/20 16:14:49 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_stack(t_stack *stack)
{
	int tmp;
	if (stack->top < 1)
		return ;
	tmp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = tmp;
}