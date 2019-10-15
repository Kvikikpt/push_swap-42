/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:55:00 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/07 22:23:32 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	a;
	char	*str;

	a = 0;
	str = NULL;
	while (s[a])
	{
		if (s[a] == c)
			str = ((char *)s + a);
		a++;
	}
	if (s[a] == c)
		return ((char *)s + a);
	if (str)
		return (str);
	return (0);
}
