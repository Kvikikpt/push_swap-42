/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:29:43 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 18:57:52 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sa_sb_ss(t_st **stack)
{
	t_st	*curr;
	t_st	*wst;

	curr = (*stack);
	if (curr)
	{
		if (curr->next)
		{
			wst = curr->next;
			curr->next = wst->next;
			wst->next = curr;
			(*stack) = wst;
		}
	}
}

void	pa_pb(t_st **stack_one, t_st **stack_two)
{
	t_st	*one;
	t_st	*two;
	t_st	*wst;

	if (*stack_one)
	{
		one = (*stack_one);
		two = (*stack_two);
		wst = one;
		one = one->next;
		wst->next = two;
		two = wst;
		(*stack_one) = one;
		(*stack_two) = two;
	}
}

void	ra_rb_rr(t_st **stack)
{
	t_st	*curr;
	t_st	*wst;
	t_st	*roll;

	curr = (*stack);
	wst = curr;
	roll = curr;
	if (curr)
	{
		if (curr->next)
		{
			curr = curr->next;
			while (roll->next)
			{
				roll = roll->next;
			}
			roll->next = wst;
			wst->next = NULL;
			(*stack) = curr;
		}
	}
}

void	rra_rrb_rrr(t_st **stack)
{
	t_st	*curr;
	t_st	*wst;
	t_st	*roll;

	curr = (*stack);
	roll = curr;
	if (curr)
	{
		if (curr->next)
		{
			while (roll->next->next)
			{
				roll = roll->next;
			}
			wst = roll;
			roll = roll->next;
			wst->next = NULL;
			roll->next = curr;
			curr = roll;
			(*stack) = curr;
			curr = curr->next;
		}
	}
}
