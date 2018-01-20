/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/20 15:02:13 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lines	*createlink()
{
	t_lines list;

	list = malloc(sizeof(t_lines));
	list->next = NULL;
	return (list);
}

t_lines	*addnmove(t_list *list)
{
	t_lines *new;
	new = createlink();
	list->next = new;
	list = list->next;
	return (list);	
}

int		issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

void	convertodouble(t_map **map, t_lines *list)
{
	int y;
	int x;

	y = 0
	while (y < (*map)->y_length)
	{
		x = 0;
		while (x < (*map)->x_width)
		{
			(*map)->map[y][x] == ft_atoi(lines->num[x]);
			x++;
		}
		lines = lines->next;
		y++;
	}
}

void	malloctosize(t_map **map)
{
	(*map)->map = malloc(sizeof(*double) * (*map)->y_length);
	while ((*map)->map[y] <= (*map)->y_length)
	{
		(*map)->map[y] == malloc(sizeof(double) * (*map)->x_width + 1)
		y++;
	}
}

int		ft_findwidth(char *line)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (issign(line[i]))
		{
			if (!ft_isdigit(line[i + 1]) && !ft_issign(line[i + 1])
				return (-1)
			i++;
		}
		if (ft_isdigit(line[i]))
		{
			count++;
			while (ft_isdigit(line[i]))	
				i++;
		}
		else if (line[i] == ' ')
		   i++;
		else
			return (-1);
	}
	return (count);	
}
/*
this part was a little rough but i got it to work. This function will go through the string
and count how many numbers there are. Also this will account for errors in the line
These errors include: strange character and signs '-' | '+' with no numbers. The length of the width
is important so I know when to stop as I traverse my 2d array. Also this will help in verifying that
the number of columns match.
*/

int		*read_map(int fd, t_map **map)
{
	t_lines	*lines;
	t_lines	*head;
	char	*line;

	lines = createlink(list);
	head = lines;
	(*map) = malloc(sizeof(t_map));
	(*map)->y_length = 0;
	while (get_next_line(fd, &line))
	{
		if ((*map)->y_length == 0)
		{
			if (((*map)->x_width = ft_findwidth(line)) < 0)
				return (0);
		}
		else
			if (ft_findwidth(line) != (*map)->x_width)
				return (0);
		lines->num = ft_strsplit(line, ' ');
		(*map)->y_length++;
		lines =	addnmove(lines);
	}
	malloctosize(map);
	converttodouble(map, head);
	return (1);
}


//	read_map will create a linked list for me to store my strsplit lines. Each line will then
//	be converted from a list of chars **chars to a list of doubles **doubles.
//	The doubles allow for more simple manipulation later.
//	An interesting point of to notice is that I am using a linked list to store the lines because
//	the size of the grid is unknown.

int main(int argc, char **argv)
{
	int fd;
	char *line;
	t_map *map;

	if (argc != 2)
	{
		ft_putendl("usage:/ one file needed");
		return (0);
	}
	fd = open(fd, O_RDONLY);
	if (!read_map(fd, &map))
	{
		ft_putendl("map error");
		return (0);
	}
	return (1);
}
