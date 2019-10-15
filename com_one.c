/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:43:55 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 18:57:47 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sa(t_st **stack, int a)
{
	if (a)
		write(1, "sa\n", 3);
	sa_sb_ss(stack);
}

void	sb(t_st **stack, int a)
{
	if (a)
		write(1, "sb\n", 3);
	sa_sb_ss(stack);
}

void	ss(t_st **stack_a, t_st **stack_b, int a)
{
	if (a)
		write(1, "ss\n", 3);
	sa_sb_ss(stack_a);
	sa_sb_ss(stack_b);
}

void	pa(t_st **stack_a, t_st **stack_b, int a)
{
	if (a)
		write(1, "pa\n", 3);
	pa_pb(stack_b, stack_a);
}

void	pb(t_st **stack_a, t_st **stack_b, int a)
{
	if (a)
		write(1, "pb\n", 3);
	pa_pb(stack_a, stack_b);
}
