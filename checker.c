/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:54:56 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 19:30:11 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	no_a(t_st **a, t_st **b, t_com_list **com, t_bonus **bonus)
{
	if (!(*a))
	{
		if (*b)
			stack_a_erase(b);
		if ((*bonus)->c)
			ft_putstr("\033[1;31mKO\n\033[0m");
		else
			ft_putstr("KO\n");
		comm_erase(com);
		bonus_erase(bonus);
		exit(1);
	}
}

void	final_check(t_st **a, t_st **b, t_com_list **com, t_bonus **bonus)
{
	t_st	*aa;

	aa = *a;
	no_a(a, b, com, bonus);
	while (aa->next)
	{
		if (aa->num > aa->next->num || *b)
		{
			if ((*bonus)->c)
				ft_putstr("\033[1;31mKO\n\033[0m");
			else
				ft_putstr("KO\n");
			if (*b)
				stack_a_erase(b);
			error_struct(com, a, bonus, 0);
		}
		aa = aa->next;
	}
	if ((*bonus)->c)
		ft_putstr("\033[1;32mOK\n\033[0m");
	else
		ft_putstr("OK\n");
	error_struct(com, a, bonus, 0);
	exit(0);
}

void	command_expand(t_st **a, t_st **b, t_com_list *com, int r)
{
	if (!ft_strcmp(com->command, "sa\0"))
		sa(a, r);
	if (!ft_strcmp(com->command, "sb\0"))
		sb(b, r);
	if (!ft_strcmp(com->command, "ss\0"))
		ss(a, b, r);
	if (!ft_strcmp(com->command, "pa\0"))
		pa(a, b, r);
	if (!ft_strcmp(com->command, "pb\0"))
		pb(a, b, r);
	if (!ft_strcmp(com->command, "ra\0"))
		ra(a, r);
	if (!ft_strcmp(com->command, "rb\0"))
		rb(b, r);
	if (!ft_strcmp(com->command, "rr\0"))
		rr(a, b, r);
	if (!ft_strcmp(com->command, "rra\0"))
		rra(a, r);
	if (!ft_strcmp(com->command, "rrb\0"))
		rrb(b, r);
	if (!ft_strcmp(com->command, "rrr\0"))
		rrr(a, b, r);
}

void	com_ex(t_com_list *com, t_bonus *bonus, t_st **a, t_st **b)
{
	t_com_list *comm;

	comm = com;
	while (comm)
	{
		if (bonus->v)
		{
			ft_putstr("\033[1;31mExec: ");
			command_expand(a, b, comm, 1);
		}
		else
			command_expand(a, b, comm, 0);
		if (bonus->v)
			print_stacks(*a, *b);
		comm = comm->next;
	}
}

int		main(int argc, char **argv)
{
	t_st			*stack_a;
	t_st			*stack_b;
	t_com_list		*com;
	t_bonus			*bonus;

	bonus = NULL;
	begin_check(argc, argv, &bonus);
	stack_a_fill(&stack_a, &argv, &bonus);
	check_dublicates(&stack_a, &bonus);
	stack_b = NULL;
	command_fill(&com, &stack_a, &bonus);
	if (bonus->v)
		print_stacks(stack_a, stack_b);
	com_ex(com, bonus, &stack_a, &stack_b);
	final_check(&stack_a, &stack_b, &com, &bonus);
}
