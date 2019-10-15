/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:32:13 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/13 19:41:37 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	a;
	char	*str;

	if (!(s && f))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	str[ft_strlen((char *)s)] = '\0';
	a = 0;
	while (s[a])
	{
		str[a] = f(a, s[a]);
		a++;
	}
	return (str);
}
