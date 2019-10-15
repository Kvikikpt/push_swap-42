/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:02:47 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 18:58:08 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		fill_num(char **str, int sign, t_st **stack_a, t_bonus **bonus)
{
	int		check;
	int		num;

	num = 0;
	while ((**str))
	{
		check = num;
		if ((**str) == ' ')
		{
			((*bonus)->a)--;
			break ;
		}
		if ((**str) > '9' || (**str) < '0')
			error(stack_a, bonus);
		if (num == 214748364 && (**str) == '8' && sign == -1)
			return (-2147483648);
		num = num * 10 + (**str) - '0';
		if ((num - ((**str) - '0')) / 10 != check || (num > 2147483647
		&& sign == 1) || (num * sign < -2147483648) || num < 0)
			error(stack_a, bonus);
		(*str)++;
	}
	return (num);
}

int		check_and_fill(char **str, t_st **stack_a, t_bonus **bonus)
{
	int		num;
	int		sign;

	while (((**str) == ' ') || ((**str) >= 9 && (**str) <= 13))
		(*str)++;
	sign = ((**str) == '-') ? -1 : 1;
	if (sign == -1 && !(*(++(*str))))
		error(stack_a, bonus);
	num = fill_num(str, sign, stack_a, bonus);
	if (num == -2147483648)
		return (num);
	num *= sign;
	return (num);
}

int		empty_check(char *str)
{
	while ((((*str) == ' ') || ((*str) >= 9 && (*str) <= 13)))
		str++;
	if (!(*str))
		return (1);
	return (0);
}

void	stack_a_fill(t_st **stack_a, char ***argv, t_bonus **bonus)
{
	int			index;
	t_st		*curr;
	t_st		*next;

	index = 1;
	(*stack_a) = st_new();
	(*stack_a)->num = check_and_fill(&((*argv)[((*bonus)->a)]), stack_a, bonus);
	(*stack_a)->index = index;
	(*stack_a)->next = NULL;
	curr = (*stack_a);
	index++;
	while ((*argv)[++((*bonus)->a)])
	{
		if (empty_check((*argv)[((*bonus)->a)]))
			continue ;
		next = st_new();
		next->num = check_and_fill(&((*argv)[((*bonus)->a)]), stack_a, bonus);
		next->index = index;
		next->next = NULL;
		curr->next = next;
		curr = curr->next;
		index++;
	}
}

int		check_dublicates(t_st **stack_a, t_bonus **bonus)
{
	t_st			*wst;
	t_st			*wst_dop;
	int				flag;
	int				a;

	flag = 0;
	a = 0;
	wst = *stack_a;
	while (wst)
	{
		wst_dop = *stack_a;
		while (wst_dop)
		{
			if (wst->num == wst_dop->num)
				flag++;
			wst_dop = wst_dop->next;
		}
		if (flag > 1)
			error(stack_a, bonus);
		flag = 0;
		a++;
		wst = wst->next;
	}
	return (a);
}
