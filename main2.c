/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/24 14:14:18 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printmap(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->y_length)
	{
		x = 0;
		while (x < map->x_width)
		{
			printf("%f ", map->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_graph *window;
	t_image	*img;

	if (argc != 2)
	{
		ft_putendl("usage:/ one file needed");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!read_map(fd, &map))
	{
		ft_putendl("map error");
		return (0);
	}
	return (0);
}


// 1. The atoi is faulty I believe and doesn't work for multiple signs only a single. Which should be good enough
// but lets just take into account.
// 
// 2. try to display the basic image it should just be a very basic 10 x 10 square with equilength vericies.
