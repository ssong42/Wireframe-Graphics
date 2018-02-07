/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:08:50 by ssong             #+#    #+#             */
/*   Updated: 2018/02/07 11:33:04 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
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

char	*ft_strjoinfree(char *final, char *end)
{
	char *buf;
	
	buf = final;
	final = ft_strjoin(buf, end);
	free(buf);
	return (final);
}

t_map	*chartostruct(char **longmap, t_map *map)
{
	int i;

	i = 0;
	map->vertices = malloc(sizeof(t_vertic) * (map->x_width * map->y_length));
	while (i < (map->x_width * map->y_length))
	{
		map->vertices[i].x = i % (int)map->x_width * map->scale;
		map->vertices[i].y = i / (int)map->x_width * map->scale;
		map->vertices[i].z = (double)(ft_atoi(longmap[i])) * map->scale;
		map->vertices[i].w = 1;
		map->vertices[i].color = 0xFFFFFF;
		i++;
	}
	return (map);
}

void	freestr(char **longmap, int x, int y)
{
	int i;

	i = 0;
	while (i < (x * y))
	{
		free (longmap[i]);
		i++;
	}
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
	char	*line;
	char	*final;
	char	**longmap;

	(*map) = malloc(sizeof(t_map));
	(*map)->y_length = 0;
	(*map)->scale = 20;
	final = NULL;
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
		(*map)->y_length++;
		line = ft_strjoinfree(line, " ");
		final = ft_strjoinfree(final, line);
	}
	longmap = ft_strsplit(final, ' ');
	*map = chartostruct(longmap, *map);
	freestr(longmap, (*map)->x_width, (*map)->y_length);
	return (1);
}

//	read_map will create a linked list for me to store my strsplit lines. Each line will then
//	be converted from a list of chars **chars to a list of doubles **doubles.
//	The doubles allow for more simple manipulation later.
//	An interesting point to notice is that I am using a linked list to store the lines because
//	the size of the grid is unknown.
