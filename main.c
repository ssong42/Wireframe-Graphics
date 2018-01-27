/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/27 13:07:34 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*initiate(t_bundle *bundle)
{
	bundle->img = malloc(sizeof(t_image));
	bundle->mouse = malloc(sizeof(t_mouse));
	bundle->mouse->init = 0;
	bundle->mlx = mlx_init();
	bundle->win = mlx_new_window(bundle->mlx, WIN_X, WIN_Y, "mlx 42");
	bundle->img->image = mlx_new_image(bundle->mlx, WIN_X, WIN_Y);
	bundle->img->ptr = mlx_get_data_addr(bundle->img->image, &bundle->img->bpp,
			&bundle->img->sizeline, &bundle->img->endian);
	bundle->img->bpp /= 8;
	return (bundle);
}

void	putpicture(t_map *map, t_image *img)
{
	int i;

	i = 0;
	while (i < (map->x_width * map->y_length))
	{
		if (map->vertices[i].x < WIN_X && map->vertices[i].x >= 0)
			if (map->vertices[i].y < WIN_Y && map->vertices[i].y >= 0)
				*(int *)(img->ptr + (map->vertices[i].x * img->bpp + (map->vertices[i].y *
								img->sizeline))) = map->vertices[i].color;
		i++;
	}
}

t_bundle *shift_trans(t_bundle *bundle)
{
	int i;

	i = 0;
	if (bundle->mouse->x != bundle->mouse->prevx || bundle->mouse->y != bundle->mouse->prevy)
	{
		while (i < (bundle->map->x_width * bundle->map->y_length))
		{
			if (bundle->mouse->x != bundle->mouse->prevx)
				bundle->map->vertices[i].x -= (bundle->mouse->prevx - bundle->mouse->x);
			if (bundle->mouse->y != bundle->mouse->prevy)
				bundle->map->vertices[i].y -= (bundle->mouse->prevy - bundle->mouse->y);
			i++;
		}
	}
	return (bundle);	
}
// buss error when the x and y are negative and try to print onto the window. 


int main(int argc, char **argv)
{
	int			fd;
	t_bundle 	*bundle;

	bundle = malloc(sizeof(t_bundle));
	if (argc != 2)
	{
		ft_putendl("usage:/ one file needed");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("open() error");
		return (0);
	}
	if (!read_map(fd, &bundle->map))
	{
		ft_putendl("map error");
		return (0);
	}
	bundle = initiate(bundle);
	putpicture(bundle->map, bundle->img);
	mlx_put_image_to_window(bundle->mlx, bundle->win, bundle->img->image, 0, 0);
	mlx_hook(bundle->win, 4, 0, mouse_click, &bundle);
	mlx_hook(bundle->win, 5, 0, mouse_release, &bundle);
	mlx_hook(bundle->win, 6, 0, mouse_move, &bundle);
	mlx_loop(bundle->mlx);
	//printmap(map);
	return (0);
}


// 1. The atoi is faulty I believe and doesn't work for multiple signs only a single. Which should be good enough
// but lets just take into account.
// 
// 2. try to display the basic image it should just be a very basic 10 x 10 square with equilength vericies.
