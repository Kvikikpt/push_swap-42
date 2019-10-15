/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:09:23 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/13 19:55:11 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	ft_whitespaces_begin(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
	{
		a++;
		if (s[a] == '\0')
			return (0);
	}
	return (a);
}

static size_t	ft_whitespaces_end(const char *s)
{
	size_t	b;
	size_t	c;

	c = 0;
	b = ft_strlen(s) - 1;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
	{
		c++;
		b--;
	}
	return (c);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	c;

	if (!s)
		return (NULL);
	a = ft_whitespaces_begin(s);
	b = ft_whitespaces_end(s);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) - a - b) + 1)))
		return (NULL);
	str[ft_strlen(s) - a - b] = '\0';
	c = 0;
	while (s[a + b])
	{
		str[c] = s[a];
		a++;
		c++;
	}
	return (str);
}
