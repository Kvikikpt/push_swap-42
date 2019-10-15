/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:05:36 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/12 15:54:31 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	a;
	char	*st1;
	char	*st2;

	a = 0;
	st1 = (char *)src;
	st2 = (char *)dest;
	if (st1 < st2)
	{
		while ((int)n > 0)
		{
			st2[n - 1] = st1[n - 1];
			n--;
		}
	}
	else
	{
		while (a < n)
		{
			st2[a] = st1[a];
			a++;
		}
	}
	return (dest);
}
