/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:30:07 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/12 15:18:00 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*st1;
	unsigned char	*st2;

	a = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (a < n)
	{
		if (st1[a] != st2[a])
			return (st1[a] - st2[a]);
		a++;
	}
	return (0);
}
