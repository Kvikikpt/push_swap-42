/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:36:48 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 19:43:59 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pre_check(t_st **a)
{
	t_st	*aa;

	aa = *a;
	while (aa->next)
	{
		if (aa->num > aa->next->num)
		{
			return ;
		}
		aa = aa->next;
	}
	stack_a_erase(a);
	exit(0);
}

void	few_elem_fill(t_st **stack_a)
{
	t_st		*wst;
	t_st		*first;
	int			min;

	min = min_stack(stack_a);
	wst = (*stack_a);
	first = wst;
	if (wst->next)
	{
		if (wst->next->num < wst->num && !wst->next->next)
			sa(stack_a, 1);
		wst = (*stack_a);
		if (wst->next->next)
		{
			if ((wst->next->num > wst->next->next->num && wst->next->next->num
			> wst->num && wst->next->num > wst->num) || (wst->num >
			wst->next->num && wst->num < wst->next->next->num) ||
			(wst->next->num < wst->num &&
			wst->next->num > wst->next->next->num))
				sa(stack_a, 1);
			a_end_roll(stack_a, min);
		}
	}
}

int		max_stack(t_st **stack)
{
	int			a;
	int			b;
	t_st		*wst;

	wst = *stack;
	b = wst->index;
	a = wst->num;
	while (wst)
	{
		if (wst->num > a)
		{
			a = wst->num;
			b = wst->index;
		}
		wst = wst->next;
	}
	return (b);
}

int		min_stack(t_st **stack)
{
	int			a;
	int			b;
	t_st		*wst;

	wst = *stack;
	b = wst->index;
	a = wst->num;
	while (wst)
	{
		if (wst->num < a)
		{
			a = wst->num;
			b = wst->index;
		}
		wst = wst->next;
	}
	return (b);
}

void	begin_check(int argc, char **argv, t_bonus **bonus)
{
	int		a;

	a = 1;
	if (argc == 1)
		exit(1);
	*bonus = bonus_new();
	while (argv[a])
	{
		if (!ft_strcmp(argv[a], "-v"))
		{
			(*bonus)->v = 1;
			((*bonus)->a)++;
		}
		if (!ft_strcmp(argv[a], "-c"))
		{
			(*bonus)->c = 1;
			((*bonus)->a)++;
		}
		a++;
	}
	if (argc <= (*bonus)->a)
		exit(1);
}
