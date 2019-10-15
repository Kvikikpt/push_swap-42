/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:24:23 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/12 15:29:50 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[a] && a < len)
	{
		b = 0;
		while (needle[b])
		{
			if (haystack[a + b] == needle[b])
			{
				b++;
				if (a + b >= len)
					break ;
			}
			else
				break ;
		}
		if (needle[b] == '\0')
			return ((char *)haystack + a);
		a++;
	}
	return (0);
}
