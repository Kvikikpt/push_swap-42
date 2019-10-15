/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:02:07 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/16 18:56:50 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	a;

	if (!(s1 && s2))
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	str[a] = '\0';
	a = 0;
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (*s2)
	{
		str[a] = *s2;
		s2++;
		a++;
	}
	return (str);
}
