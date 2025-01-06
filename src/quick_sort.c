/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:39:19 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/06 17:26:12 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static void copy_array(int *array, int *tab, int len)
{
    int	i;

    i = -1;
    while (++i < len)
        tab[i] = array[i];
}

static int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int array[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}

static void	doublon_and_fin(int array[], int len, t_mq **mq)
{
	int	i;
	int	tmp;
	int	l;

	i = 0;
	tmp = array[0];
	l = 1;
	while (++i < len)
	{
		if (array[i] == tmp)
			l = 0;
		tmp = array[i];
	}
	(*mq)->len = len;
	if (!l)
		(*mq)->len = l;
	(*mq)->med = (len + 1) / 2;
	fill_mq(mq, len, array);
}

void	get_median_quartil(t_stack *stack_a, t_mq **mq, int *error)
{
	int		len;
	int		*tab;

    tab = malloc(sizeof(int) * stack_a->size);
    if (!tab)
        return ;
    copy_array(stack_a->data, tab, stack_a->size);
	quick_sort(tab, 0, len - 1);
	doublon_and_fin(tab, len, mq);
	(*mq)->med = tab[((*mq)->med) - 1];
	free(tab);
}