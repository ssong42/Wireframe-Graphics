/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:19:02 by ssong             #+#    #+#             */
/*   Updated: 2018/02/02 13:26:45 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUFF_SIZE 50

t_double	*addnode(t_double *tmp, int fd)
{
	t_double *end;

	end = malloc(sizeof(t_double));
	end->str = malloc(sizeof(char));
	end->str[0] = '\0';
	end->fd = fd;
	end->next = NULL;
	if (tmp == NULL)
		return (end);
	else
		tmp->next = end;
	return (end);
}

t_double	*searchfd(t_double **array, int fd)
{
	t_double *tmp;

	tmp = *array;
	if (*array == NULL)
	{
		*array = addnode(tmp, fd);
		return (*array);
	}
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			tmp = addnode(tmp, fd);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

int			set_string(t_double **array, char ***line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*array)->str[i] != 0 && (*array)->str[i] != '\n')
		i++;
	if ((*array)->str[i] == 0)
	{
		**line = ft_strdup((*array)->str);
		if (i == 0)
			return (0);
		temp = ft_strdup((*array)->str + i);
		free((*array)->str);
		(*array)->str = temp;
	}
	else if ((*array)->str[i] == '\n')
	{
		(*array)->str[i] = 0;
		**line = ft_strdup((*array)->str);
		temp = ft_strdup((*array)->str + i + 1);
		free((*array)->str);
		(*array)->str = temp;
	}
	return (1);
}

t_double	*delnode(t_double **tmp, t_double *array)
{
	t_double *head;

	head = array;
	while (array->next != *tmp && array != *tmp)
	{
		array = array->next;
	}
	if (array != *tmp)
		array->next = (*tmp)->next;
	ft_strdel(&(*tmp)->str);
	ft_memdel((void **)(tmp));
	return (head);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static t_double *array = NULL;
	char			buf[BUFF_SIZE + 1];
	t_double		*tmp;
	char			*temp;

	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	tmp = searchfd(&array, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		temp = ft_strjoin(tmp->str, buf);
		free(tmp->str);
		tmp->str = temp;
	}
	if (set_string(&tmp, &line) == 0)
	{
		array = delnode(&tmp, array);
		return (0);
	}
	return (1);
}
