/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:51:29 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/20 18:09:28 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	a;

	a = 0;
	while (s[a])
		a++;
	if (!(str = (char *)malloc(sizeof(char) * a + 1)))
		return (NULL);
	str[a] = '\0';
	a = 0;
	while (s[a])
	{
		str[a] = s[a];
		a++;
	}
	return (str);
}
