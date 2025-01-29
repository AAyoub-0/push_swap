/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:56 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/29 16:05:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char)s1[i] == (unsigned char)s2[i]) && (s1[i] && s2[i])
		&& (i < n - 1))
		i++;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}

t_bool	ft_strcmp(char *str, char *s1)
{
	int	i;

	i = 0;
	while (s1[i] && str[i] && str[i] == s1[i])
		i++;
	if (!s1[i] && !str[i])
		return (true);
	return (false);
}
