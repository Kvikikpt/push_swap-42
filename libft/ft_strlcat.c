/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:20:53 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/11 19:25:58 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	count;

	a = 0;
	b = 0;
	count = 0;
	while (dst[a])
		a++;
	while (src[count])
		count++;
	if (size <= a)
		return (count + size);
	else
		count += a;
	while (src[b] && a + 1 < size)
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (count);
}
