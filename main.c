/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/02/05 10:18:59 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*initiate(t_bundle *bundle)
{
	bundle->img = malloc(sizeof(t_image));
	bundle->mouse = malloc(sizeof(t_mouse));
	bundle->mouse->init = 0;
	bundle->thetax = 0;
	bundle->thetay = 0;
	bundle->ctrlpressed = 0;
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
				*(int *)(img->ptr + ((int)map->vertices[i].x * img->bpp  +
					((int)map->vertices[i].y * img->sizeline))) = map->vertices[i].color;
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

t_bundle *zoomout_trans(t_bundle *bundle)
{
	int i;
	
	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		bundle->map->vertices[i].x -= bundle->zoom/2;
		bundle->map->vertices[i].y -= bundle->zoom/2;
		i++;
	}
	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		i++;
	}
	return (bundle);
}

t_bundle *zoomin_trans(t_bundle *bundle)
{
	int i;
	
	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		i++;
	}
	return (bundle);
}

int main	(int argc, char **argv)
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
	bundle->middle_x = bundle->map->x_width * bundle->map->scale / 2;
	bundle->middle_y = bundle->map->y_length * bundle->map->scale / 2;
	converttocenter(bundle);
	putpicture(bundle->map, bundle->img);
	mlx_put_image_to_window(bundle->mlx, bundle->win, bundle->img->image, 0, 0);
	mlx_hook(bundle->win, 2, 0, key_press, &bundle);
	mlx_hook(bundle->win, 3, 0, key_release, &bundle);
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
