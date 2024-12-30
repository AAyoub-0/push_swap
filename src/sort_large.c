/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:54:16 by aayoub            #+#    #+#             */
/*   Updated: 2024/12/24 18:41:09 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void   merge_sort(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int mid;

    if (start >= end)
        return ;
    mid = (start + end) / 2;
    merge_sort(stack_a, stack_b, start, mid);
    merge_sort(stack_a, stack_b, mid + 1, end);
    split_stack(stack_a, stack_b, start, end); 
}

void    split_stack(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
    int mid;
    int i;
    int j;
    int k;
    
    mid = (start + end) / 2;
    i = start;
    j = mid + 1;
    k = start;
    while (i <= mid && j <= end)
    {
        if (stack_a->data[i] < stack_a->data[j])
            stack_b->data[k++] = stack_a->data[i++];
        else
            stack_b->data[k++] = stack_a->data[j++];
    }
    while (i <= mid)
        stack_b->data[k++] = stack_a->data[i++];
    while (j <= end)
        stack_b->data[k++] = stack_a->data[j++];
    i = start;
    while (i <= end)
    {
        stack_a->data[i] = stack_b->data[i];
        i++;
    }
}
