/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:18:46 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/15 17:11:28 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	str_nbr_len(int n)
{
	size_t	a;

	a = 1;
	while (n /= 10)
		a++;
	return (a);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			a;
	unsigned int	nbr;

	a = str_nbr_len(n);
	if (n < 0)
	{
		nbr = -1 * n;
		a++;
	}
	else
		nbr = n;
	if (!(str = (char *)malloc(sizeof(char) * a + 1)))
		return (NULL);
	str[a] = '\0';
	while (nbr)
	{
		str[--a] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
