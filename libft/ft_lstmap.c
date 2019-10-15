/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:21:52 by cnikia            #+#    #+#             */
/*   Updated: 2019/04/15 17:17:03 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*a;
	t_list	*start;

	if (!(lst && f))
		return (NULL);
	a = f(lst);
	if (!(list = ft_lstnew(a->content, a->content_size)))
		return (NULL);
	lst = lst->next;
	start = list;
	while (lst)
	{
		a = f(lst);
		if (!(list->next = ft_lstnew(a->content, a->content_size)))
		{
			return (NULL);
			free(list);
		}
		list = list->next;
		lst = lst->next;
	}
	return (start);
}
