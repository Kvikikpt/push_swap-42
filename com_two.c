/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:49:35 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 18:57:50 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ra(t_st **stack, int a)
{
	if (a)
		write(1, "ra\n", 3);
	ra_rb_rr(stack);
}

void	rb(t_st **stack, int a)
{
	if (a)
		write(1, "rb\n", 3);
	ra_rb_rr(stack);
}

void	rr(t_st **stack_a, t_st **stack_b, int a)
{
	if (a)
		write(1, "rr\n", 3);
	ra_rb_rr(stack_a);
	ra_rb_rr(stack_b);
}

void	rra(t_st **stack, int a)
{
	if (a)
		write(1, "rra\n", 4);
	rra_rrb_rrr(stack);
}

void	rrb(t_st **stack, int a)
{
	if (a)
		write(1, "rrb\n", 4);
	rra_rrb_rrr(stack);
}
