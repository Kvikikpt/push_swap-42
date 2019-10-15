/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:22:12 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/27 18:59:24 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_st		*st_new(void)
{
	t_st	*new;

	new = NULL;
	if ((new = (t_st *)malloc(sizeof(t_st))))
	{
		new->next = NULL;
	}
	return (new);
}

t_com_list	*command_new(void)
{
	t_com_list	*new;

	new = NULL;
	if ((new = (t_com_list *)malloc(sizeof(t_com_list))))
	{
		new->command = NULL;
		new->next = NULL;
	}
	return (new);
}

int			check(char *str)
{
	if (!ft_strcmp(str, "sa\0") || !ft_strcmp(str, "sb\0") ||
	!ft_strcmp(str, "ss\0") || !ft_strcmp(str, "pa\0") ||
	!ft_strcmp(str, "pb\0") || !ft_strcmp(str, "ra\0") ||
	!ft_strcmp(str, "rb\0") || !ft_strcmp(str, "rr\0") ||
	!ft_strcmp(str, "rra\0") || !ft_strcmp(str, "rrb\0") ||
	!ft_strcmp(str, "rrr\0"))
		return (1);
	else
		return (0);
}

void		command_fill_cycle(t_com_list **com, t_st **a,
char *str, t_bonus **bonus)
{
	t_com_list	*curr;
	t_com_list	*next;

	curr = (*com);
	while (get_next_line(0, &str))
	{
		if (str[0] == '\0')
		{
			free(str);
			break ;
		}
		if (!check(str))
			error_struct(com, a, bonus, 1);
		next = command_new();
		next->command = str;
		next->next = NULL;
		curr->next = next;
		curr = curr->next;
	}
}

void		command_fill(t_com_list **com, t_st **a, t_bonus **bonus)
{
	char		*str;

	str = NULL;
	(*com) = command_new();
	if (!(get_next_line(0, &str)))
		error_struct(com, a, bonus, 1);
	if (str[0] == '\0')
	{
		free(str);
		comm_erase(com);
		return ;
	}
	if (!check(str))
		error_struct(com, a, bonus, 1);
	(*com)->command = str;
	command_fill_cycle(com, a, str, bonus);
}
