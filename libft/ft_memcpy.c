/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:14:48 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/17 17:31:24 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*st1;
	unsigned char	*st2;

	if (n == 0 || dest == src)
		return (dest);
	a = 0;
	st1 = (unsigned char *)src;
	st2 = (unsigned char *)dest;
	while (a < n)
	{
		st2[a] = st1[a];
		a++;
	}
	return (dest);
}
