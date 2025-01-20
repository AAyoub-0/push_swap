/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:34:53 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/20 20:30:50 by aayoub           ###   ########.fr       */
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
int	main(void)
{
	srand(time(NULL));
	size_3_test();
	size_4_test();
	size_5_test();
	size_100_test();
	size_500_test();
	return (0);
}
