/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:28:05 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 19:00:28 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	com_done_extra(t_st **bbb, t_st **a, t_st **b)
{
	while ((*bbb)->com[1] > 0 && (*bbb)->com[3] > 0)
	{
		rr(a, b, 1);
		((*bbb)->com[1])--;
		((*bbb)->com[3])--;
	}
	while ((*bbb)->com[2] > 0 && (*bbb)->com[4] > 0)
	{
		rrr(a, b, 1);
		((*bbb)->com[2])--;
		((*bbb)->com[4])--;
	}
}

void	com_done(t_st **bbb, t_st **a, t_st **b)
{
	com_done_extra(bbb, a, b);
	while ((*bbb)->com[1] > 0)
	{
		rb(b, 1);
		((*bbb)->com[1])--;
	}
	while ((*bbb)->com[2] > 0)
	{
		rrb(b, 1);
		((*bbb)->com[2])--;
	}
	while ((*bbb)->com[3] > 0)
	{
		ra(a, 1);
		((*bbb)->com[3])--;
	}
	while ((*bbb)->com[4] > 0)
	{
		rra(a, 1);
		((*bbb)->com[4])--;
	}
	pa(a, b, 1);
}

void	b_erase(t_st **a, t_st **b, t_bonus **bonus)
{
	t_st		*bb;
	t_st		*bbb;
	int			curr;

	bb = *b;
	while (bb)
	{
		bbb = *b;
		stack_b_check_roll(b);
		stack_a_check_roll(a, b);
		print_check(*a, *b, bonus);
		curr = bbb->com[0];
		while (bbb)
		{
			if (bbb->com[0] < curr)
				curr = bbb->com[0];
			bbb = bbb->next;
		}
		bbb = *b;
		while (bbb->com[0] != curr)
			bbb = bbb->next;
		com_done(&bbb, a, b);
		if (*b == NULL)
			bb = NULL;
	}
}

void	elem_fill(t_st **a, t_st **b, t_bonus **bonus)
{
	int			max;
	int			min;
	t_st		*bb;

	bb = *b;
	max = max_stack(a);
	min = min_stack(a);
	while ((*a)->next->next->next)
	{
		if ((*a)->index == max || (*a)->index == min)
			ra(a, 1);
		else
			pb(a, b, 1);
	}
	if ((*a)->next->next)
	{
		if (((*a)->next->num > (*a)->next->next->num && (*a)->next->next->num
		> (*a)->num && (*a)->next->num > (*a)->num) || ((*a)->num >
		(*a)->next->num && (*a)->num < (*a)->next->next->num) ||
		((*a)->next->num < (*a)->num &&
		(*a)->next->num > (*a)->next->next->num))
			sa(a, 1);
	}
	b_erase(a, b, bonus);
	a_end_roll(a, min);
}

int		main(int argc, char **argv)
{
	t_st			*stack_a;
	t_st			*stack_b;
	t_bonus			*bonus;
	int				a;

	bonus = NULL;
	begin_check(argc, argv, &bonus);
	if (bonus->c)
		ft_putstr("\033[1;34m");
	stack_a = NULL;
	stack_a_fill(&stack_a, &argv, &bonus);
	stack_b = NULL;
	a = check_dublicates(&stack_a, &bonus);
	pre_check(&stack_a);
	if (a > 3)
	{
		elem_fill(&stack_a, &stack_b, &bonus);
	}
	else
		few_elem_fill(&stack_a);
	stack_a_erase(&stack_a);
	if (bonus->c)
		ft_putstr("\033[0m");
	bonus_erase(&bonus);
}
