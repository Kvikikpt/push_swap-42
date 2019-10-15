/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:37:05 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 19:09:31 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	error(t_st **a, t_bonus **bonus)
{
	stack_a_erase(a);
	bonus_erase(bonus);
	ft_putstr("Error\n");
	exit(1);
}

void	error_struct(t_com_list **com, t_st **a, t_bonus **bonus, int error)
{
	comm_erase(com);
	stack_a_erase(a);
	bonus_erase(bonus);
	if (error)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	exit(2);
}

void	stack_a_erase(t_st **a)
{
	t_st	*curr;
	t_st	*erase;

	curr = *a;
	while (curr)
	{
		erase = curr;
		curr = curr->next;
		if (erase)
			free(erase);
	}
	*a = NULL;
}

void	comm_erase(t_com_list **comm)
{
	t_com_list	*wst;

	while (*comm)
	{
		wst = *comm;
		(*comm) = (*comm)->next;
		if (wst)
		{
			if (wst->command)
				free(wst->command);
			free(wst);
		}
		wst = NULL;
	}
}

void	bonus_erase(t_bonus **bonus)
{
	if (*bonus)
		free(*bonus);
}
