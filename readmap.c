/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:08:50 by ssong             #+#    #+#             */
/*   Updated: 2018/01/24 14:12:10 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

void	converttodouble(t_map **map, t_lines *list)
{
	int y;
	int x;

	y = 0;
	while (y < (*map)->y_length)
	{
		x = 0;
		while (x < (*map)->x_width)
		{
			(*map)->map[y][x] = ft_atoi(list->num[x]);
			x++;
		}
		list = list->next;
		y++;
	}
}

void	malloctosize(t_map **map)
{
	int y;

	y = 0;
	(*map)->map = (double**)malloc(sizeof(double*) * (*map)->y_length);
	while (y <= (*map)->y_length)
	{
		(*map)->map[y] = (double*)malloc(sizeof(double) * (*map)->x_width + 1);
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
			if (!ft_isdigit(line[i + 1]) && !issign(line[i + 1]))
				return (-1);
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

int		read_map(int fd, t_map **map)
{
	t_lines	*lines;
	t_lines	*head;
	char	*line;

	lines = createlink();
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
		lines->y = (*map)->y_length;
		(*map)->y_length++;
		lines =	addnmove(lines);
	}
	// the t_list of lines need to store their respective y locations for use later
	// mallocanarray of a struct for the verticies in side the map: with the size of (x_width * y_width + 1); NULL TERMINATED
	// Convert the t_list of lines into x, y, and z data within the array of structs. Traversal within the lines and
	// traversal within the array will be different.
	//
	//malloctosize(map);
	//converttodouble(map, head);
	return (1);
}

//	read_map will create a linked list for me to store my strsplit lines. Each line will then
//	be converted from a list of chars **chars to a list of doubles **doubles.
//	The doubles allow for more simple manipulation later.
//	An interesting point to notice is that I am using a linked list to store the lines because
//	the size of the grid is unknown.
