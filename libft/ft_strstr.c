/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:58:10 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/13 19:57:23 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[a])
	{
		b = 0;
		while (needle[b])
		{
			if (haystack[a + b] == needle[b])
				b++;
			else
				break ;
		}
		if (needle[b] == '\0')
			return ((char *)haystack + a);
		a++;
	}
	return (NULL);
}
