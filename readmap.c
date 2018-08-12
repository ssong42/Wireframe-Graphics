/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:08:50 by ssong             #+#    #+#             */
/*   Updated: 2018/03/07 11:28:57 by ssong            ###   ########.fr       */
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

/*
**	ft_findwidth will find the number of numbers in the string.
**	as well as check for format errors in the input file
**	it will return -1 if file is false or the number of
**	numbers inside the string.
*/

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
		map->vertices[i].ogz = map->vertices[i].z;
		map->vertices[i].w = 1;
		if (map->vertices[i].z > 0 || map->vertices[i].z < 0)
			map->vertices[i].color = 0xFF0000;
		else
			map->vertices[i].color = 0x00FF00;
		i++;
	}
	return (map);
}

t_map	*init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->y_length = 0;
	map->scale = 20;
	return (map);
}

int		read_map(int fd, t_map **map)
{
	char	*line;
	char	*final;
	char	**longmap;

	*map = init_map(*map);
	final = NULL;
	while (get_next_line(fd, &line))
	{
		if ((*map)->y_length == 0)
		{
			if (((*map)->x_width = ft_findwidth(line)) < 0)
				return (0);
		}
		else if (ft_findwidth(line) != (*map)->x_width)
			return (0);
		(*map)->y_length++;
		line = ft_strjoinfree(line, " ");
		final = ft_strjoinfree(final, line);
	}
	longmap = ft_strsplit(final, ' ');
	*map = chartostruct(longmap, *map);
	ft_free2darray(longmap, (*map)->x_width, (*map)->y_length);
	return (1);
}

/*
**	1. get_next_line used to separate the file line by line
**	2. one long string is createed with strjoin
**	3. each individual is check from right width and characters
**	4. the 2d string is then converted to the vertices struct
**	5. free it all.
*/
