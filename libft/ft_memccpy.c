/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:28:50 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/17 17:32:08 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			a;

	if (!n)
		return (NULL);
	a = 0;
	st1 = (unsigned char *)src;
	st2 = (unsigned char *)dest;
	while (a < n)
	{
		st2[a] = st1[a];
		if (st1[a] == (unsigned char)c)
			return (dest + a + 1);
		a++;
	}
	return (NULL);
}
