/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:21:16 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/15 17:01:48 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_atoi(const char *str)
{
	size_t					a;
	unsigned long int		n;
	unsigned long int		b;
	int						sign;

	a = 0;
	n = 0;
	sign = 1;
	while ((str[a] == ' ') || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = -1;
		a++;
	}
	while (str[a] <= '9' && str[a] >= '0')
	{
		b = n;
		n = (n * 10) + (str[a] - '0');
		if (((n - (str[a] - '0')) / 10) != b)
			return (-1);
		a++;
	}
	return (n * sign);
}
