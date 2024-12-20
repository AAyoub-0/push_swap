/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/20 16:41:31 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
    t_stack *stack = stack_create(3);
    stack_push(stack, 3);
    stack_push(stack, 2);
    stack_push(stack, 1);

    stack_print(stack);
    printf("sorting tab\n");
    sort_three(stack);
    stack_print(stack);
    
}