/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:54:16 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/06 17:27:22 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"


static void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_mq *mq)
{
	if (mq->len == 2)
		if (stack_a->data[0] > stack_a->data[1])
			write(1, "sa\n", 3);
	if (mq->len > 2)
		if (!is_sorted(stack_a))
			push_b_optimize(stack_a, stack_b, mq);
	stack_destroy(stack_a);
    stack_destroy(stack_b);
	exit(1);
}

int	sort_large(t_stack *stack_a, t_stack *stack_b)
{
    t_mq	*mq;
    int        error;

    mq = malloc(sizeof(t_mq));
    if (!mq)
        exit (1);
    error = 0;
	get_median_quartil(stack_a, &mq, &error);
	if (error || mq->len == 0 || !mq)
	{
		write(2, "Error\n", 6);
		if (mq)
			free(mq);
		return (1);
	}
	launch_algo(stack_a, stack_b, mq);
	stack_destroy(stack_a);
    stack_destroy(stack_b);
	free(mq);
	return (0);
}
