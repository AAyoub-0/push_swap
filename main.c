/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 23:27:41 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int	main(int ac, char **av)
// {
// 	char	*str;
// 	if (ac < 2)
// 		exit(1);
// 	str = join_args(ac, av);
// 	if (!is_valid_args(str))
// 	{
// 		ft_printf("Error\n");
// 		exit(1);
// 	}
//     t_stack *a = stack_create_from_str(str, 'a');
// 	if (!check_doubls(a))
// 	{
// 		ft_printf("Error\n");
// 		exit(stack_destroy(a));
// 	}
// 	t_stack *b = stack_create(a->size, 'b');
// 	sort(a, b);
// 	return (0);
// }

# include <time.h>
int	main(int ac, char **av)
{
	// first arg is the number of tests to run and the second is the size of the array
	srand(time(NULL));
	if (ac != 3)
	{
		printf("Usage: %s <number of tests> <size of the array>\n", av[0]);
		exit(1);
	}
	int test = ft_atoi(av[1]);
	int size = ft_atoi(av[2]);
	if (size == 3)
		size_3_test();
	else if (size == 4)
		size_4_test();
	else if (size == 5)
		size_5_test();
	else if (size == 100)
		size_100_test(test);
	else if (size == 500)
		size_500_test(test);
	else
		size_n_test(size, test);
	return (0);
}
