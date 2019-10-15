/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:07:48 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/11 18:42:45 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	ft_putchar_fd_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -1 * (unsigned int)n;
	}
	else
		nbr = (unsigned int)n;
	if (nbr < 10)
		ft_putchar_fd_fd((char)(nbr + '0'), fd);
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd_fd((char)(nbr % 10 + '0'), fd);
	}
}
