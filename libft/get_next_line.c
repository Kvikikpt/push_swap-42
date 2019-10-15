/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:43:04 by cnikia            #+#    #+#             */
/*   Updated: 2019/09/03 17:12:35 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	content_del(t_list *list)
{
	if (list->content)
	{
		free(list->content);
		list->content = NULL;
	}
}

t_list	*list_curr(t_list **list, int fd)
{
	t_list	*curr;

	curr = *list;
	while (curr)
	{
		if ((int)curr->content_size == fd)
			return (curr);
		curr = curr->next;
	}
	curr = ft_lstnew("\0", 1);
	curr->content_size = fd;
	ft_lstadd(list, curr);
	curr = *list;
	return (curr);
}

void	ft_gnl_str(char **line, t_list *curr)
{
	size_t	a;
	char	*str;
	char	*wst;

	a = 0;
	str = (char *)curr->content;
	while (str[a] != '\n' && str[a])
		a++;
	if (str[a] == '\n')
	{
		if (!(*line = ft_strsub(str, 0, a)))
			return ;
		str = str + a + 1;
		wst = ft_strdup(str);
		content_del(curr);
		if (*wst)
			curr->content = wst;
		else
			free(wst);
	}
	else if (!str[a])
	{
		*line = ft_strdup(str);
		content_del(curr);
	}
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static t_list	*list;
	t_list			*curr;
	char			buf[BUFF_SIZE + 1];
	char			*wst;

	if ((fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	curr = list_curr(&list, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(curr->content))
			curr->content = ft_strnew(1);
		if (!(wst = ft_strjoin((char *)curr->content, buf)))
			return (-1);
		content_del(curr);
		curr->content = wst;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == 0 && !(curr->content))
		return (0);
	ft_gnl_str(line, curr);
	return (1);
}
