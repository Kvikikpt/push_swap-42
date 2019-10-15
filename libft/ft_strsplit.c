/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:05:24 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/16 15:06:37 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	world_count(char const *s, char c)
{
	size_t	a;
	size_t	count;

	a = 0;
	count = 0;
	while (s[a])
	{
		if (s[a] != c && (s[a + 1] == c || s[a + 1] == '\0'))
			count++;
		a++;
	}
	return (count);
}

static size_t	letter_count(char const *s, char c, size_t a)
{
	size_t	count;
	size_t	b;

	b = a;
	count = 0;
	while (s[b] != c && s[b])
	{
		count++;
		b++;
	}
	return (count);
}

static char		**ft_strsplit_mainc(char const *s, char c, char **str, int arr)
{
	size_t	d;
	size_t	a;

	a = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			d = letter_count(s, c, a);
			if (!(str[++arr] = (char *)malloc(sizeof(char) * d + 1)))
				return (NULL);
			str[arr][d] = '\0';
			d = 0;
			while (s[a] != c && s[a])
			{
				str[arr][d] = s[a];
				a++;
				d++;
			}
		}
		else
			a++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**str;
	int				arr;

	if (!(s && c))
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (world_count(s, c) + 1))))
		return (NULL);
	str[world_count(s, c)] = 0;
	arr = -1;
	str = ft_strsplit_mainc(s, c, str, arr);
	return (str);
}
