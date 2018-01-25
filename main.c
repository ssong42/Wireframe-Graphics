/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/25 14:45:13 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printmap(t_map *map)
{
	int i;

	i = 0;
	while (i < (map->x_width * map->y_length))
	{
		printf("(%d, %d) ", map->vertices[i].x, map->vertices[i].y);
		//printf("%d ", (int)map->vertices[i].z);
		i++;
		if (i % map->x_width == 0)
			printf("\n");
	}
}

void	initiate(t_win **window, t_image **img)
{
	(*img) = malloc(sizeof(t_image));
	(*window) = malloc(sizeof(t_win));
	(*window)->mlx = mlx_init();
	(*window)->win = mlx_new_window((*window)->mlx, 1200, 700, "mlx 42");
	(*img)->image = mlx_new_image((*window)->mlx, 1200, 700);
	(*img)->ptr = mlx_get_data_addr((*img)->image, &(*img)->bpp, &(*img)->sizeline, &(*img)->endian);
	(*img)->bpp /= 8;
}

int main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_win *window;
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
	initiate(&window, &img);
	int i = 0;
	while (i < (map->x_width * map->y_length))
	{
		if (map->vertices[i].x < 1200)
			if (map->vertices[i].y < 700)
				*(int *)(img->ptr + (map->vertices[i].x * img->bpp + (map->vertices[i].y * img->sizeline))) = map->vertices[i].color;
		i++;
	}
	mlx_put_image_to_window(window->mlx, window->win, img->image, 0, 0);
	mlx_loop(window->mlx);

	//printmap(map);
	return (0);
}


// 1. The atoi is faulty I believe and doesn't work for multiple signs only a single. Which should be good enough
// but lets just take into account.
// 
// 2. try to display the basic image it should just be a very basic 10 x 10 square with equilength vericies.
