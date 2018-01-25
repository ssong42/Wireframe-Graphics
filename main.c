/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/25 10:03:10 by ssong            ###   ########.fr       */
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
	int y;
	int x;

	y = 0;
	x = 0;
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
	img = malloc(sizeof(t_image));
	window = malloc(sizeof(t_graph));
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 1200, 720, "mlx 42");
	img->image = mlx_new_image(window->mlx, 1200, 700);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->sizeline, &img->endian);
	img->bpp /= 8;
	img->dist = 15;
	while (y < map->y_length)
	{
		x = 0;
		while (x < map->x_width)
		{
			*(int *)(img->ptr + (x * img->dist * img->bpp + (y * img->dist * img->sizeline))) = 0xFFFFFF;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx, window->win, img->image, 50, 50);
	mlx_loop(window->mlx);
	return (0);
}


// 1. The atoi is faulty I believe and doesn't work for multiple signs only a single. Which should be good enough
// but lets just take into account.
// 
// 2. try to display the basic image it should just be a very basic 10 x 10 square with equilength vericies.
