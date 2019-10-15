/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:04:19 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 18:57:58 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	stack_b_check_roll_help(t_st **bb, t_st **curr)
{
	int		begin;
	int		end;

	begin = 0;
	while ((*curr) != (*bb))
	{
		(*curr) = (*curr)->next;
		begin++;
	}
	end = 1;
	while ((*curr)->next)
	{
		(*curr) = (*curr)->next;
		end++;
	}
	(*bb)->com[0] = (end > begin) ? begin : end;
	if (end > begin)
		(*bb)->com[1] = begin;
	else
		(*bb)->com[2] = end;
}

void	stack_b_check_roll(t_st **b)
{
	t_st		*curr;
	t_st		*bb;

	bb = *b;
	while (bb)
	{
		bb->com[0] = -1;
		bb->com[1] = -1;
		bb->com[2] = -1;
		bb->com[3] = -1;
		bb->com[4] = -1;
		curr = *b;
		stack_b_check_roll_help(&bb, &curr);
		bb = bb->next;
	}
}

void	stack_a_check_roll_help(t_st **aa, t_st **bb, t_st **prev)
{
	int		begin;
	int		end;

	begin = 0;
	end = 1;
	while ((*aa)->next)
	{
		if ((*bb)->num < (*aa)->num && (*bb)->num > (*prev)->num)
			break ;
		begin++;
		(*prev) = (*aa);
		(*aa) = (*aa)->next;
	}
	while ((*aa)->next)
	{
		(*aa) = (*aa)->next;
		end++;
	}
	(*bb)->com[0] += (end > begin) ? begin : end;
	if (end > begin)
		(*bb)->com[3] = begin;
	else
		(*bb)->com[4] = end;
}

void	stack_a_check_roll(t_st **a, t_st **b)
{
	t_st		*last;
	t_st		*prev;
	t_st		*bb;
	t_st		*aa;

	bb = *b;
	last = *a;
	while (last->next)
		last = last->next;
	while (bb)
	{
		prev = last;
		aa = *a;
		stack_a_check_roll_help(&aa, &bb, &prev);
		bb = bb->next;
	}
}

void	a_end_roll(t_st **a, int min)
{
	int			begin;
	int			end;
	t_st		*curr;

	curr = *a;
	begin = 0;
	while (curr->index != min)
	{
		curr = curr->next;
		begin++;
	}
	end = 1;
	while (curr->next)
	{
		curr = curr->next;
		end++;
	}
	if (begin < end)
		while ((*a)->index != min)
			ra(a, 1);
	else
		while ((*a)->index != min)
			rra(a, 1);
}
