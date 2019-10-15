/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:05:32 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 19:41:58 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_palochki(int c)
{
	ft_putstr("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	ft_putstr("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	ft_putstr("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	if (c)
		ft_putstr("=\\");
	else
		ft_putstr("=/");
}

void	print_stacks(t_st *a, t_st *b)
{
	ft_putstr("\n\033[1;36m/");
	print_palochki(1);
	ft_putstr("\na: \033[1;32m");
	if (!a)
		ft_putstr("---");
	while (a)
	{
		ft_putnbr(a->num);
		ft_putstr(" ");
		a = a->next;
	}
	ft_putstr("\n\033[1;36mb: \033[1;35m");
	if (!b)
		ft_putstr("---");
	while (b)
	{
		ft_putnbr(b->num);
		ft_putstr(" ");
		b = b->next;
	}
	ft_putstr("\033[1;36m\n\\");
	print_palochki(0);
	ft_putstr("\n\033[0m\n");
}

t_bonus	*bonus_new(void)
{
	t_bonus		*new;

	new = NULL;
	if ((new = (t_bonus *)malloc(sizeof(t_bonus))))
	{
		new->v = 0;
		new->c = 0;
		new->a = 1;
	}
	return (new);
}

void	print_check_extra(t_st **wst, t_bonus **bonus)
{
	while (*wst)
	{
		if ((*bonus)->c)
			ft_putstr("\033[1;35m");
		ft_putnbr((*wst)->num);
		ft_putstr(":");
		if ((*bonus)->c)
			ft_putstr("\033[1;33m");
		ft_putnbr((*wst)->com[0]);
		ft_putchar('/');
		if ((*bonus)->c)
			ft_putstr("\033[1;36m");
		ft_putnbr((*wst)->com[1]);
		ft_putchar('|');
		ft_putnbr((*wst)->com[2]);
		ft_putchar('|');
		ft_putnbr((*wst)->com[3]);
		ft_putchar('|');
		ft_putnbr((*wst)->com[4]);
		ft_putchar(' ');
		(*wst) = (*wst)->next;
	}
}

void	print_check(t_st *a, t_st *b, t_bonus **bonus)
{
	t_st	*wst;

	if (!(*bonus)->v)
		return ;
	wst = a;
	if ((*bonus)->c)
		ft_putstr("\033[1;34m");
	ft_putstr("a: ");
	if ((*bonus)->c)
		ft_putstr("\033[1;32m");
	while (wst)
	{
		ft_putnbr(wst->num);
		ft_putchar(' ');
		wst = wst->next;
	}
	wst = b;
	if ((*bonus)->c)
		ft_putstr("\033[1;34m");
	ft_putstr("\nb-stack: ");
	print_check_extra(&wst, bonus);
	if ((*bonus)->c)
		ft_putstr("\033[1;34m");
	ft_putchar('\n');
}
