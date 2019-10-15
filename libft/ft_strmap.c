/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:16:38 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/13 19:40:18 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	a;

	if (!(s && f))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	str[ft_strlen((char *)s)] = '\0';
	a = 0;
	while (s[a])
	{
		str[a] = f(s[a]);
		a++;
	}
	return (str);
}
