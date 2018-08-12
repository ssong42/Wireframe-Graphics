/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:54:20 by ssong             #+#    #+#             */
/*   Updated: 2018/02/26 15:41:50 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*bundle_init(t_bundle *bundle)
{
	converttocenter(bundle);
	rotate_trans(bundle);
	converttocenterimage(bundle);
	putpicture(bundle->map, bundle->img);
	ddalines(bundle);
	return (bundle);
}

t_bundle	*initiate(t_bundle *bundle)
{
	bundle->img = malloc(sizeof(t_image));
	bundle->mouse = malloc(sizeof(t_mouse));
	bundle->mouse->init = 0;
	bundle->thetay = 0;
	bundle->thetax = 0;
	bundle->thetaz = 0;
	bundle->thetapx = 0;
	bundle->thetapy = 0;
	bundle->middle_x = (bundle->map->x_width - 1) * bundle->map->scale / 2;
	bundle->middle_y = (bundle->map->y_length - 1) * bundle->map->scale / 2;
	bundle->ctrlpressed = 0;
	bundle->mlx = mlx_init();
	bundle->win = mlx_new_window(bundle->mlx, WIN_X, WIN_Y, "mlx 42");
	bundle->img->image = mlx_new_image(bundle->mlx, WIN_X, WIN_Y);
	bundle->img->ptr = mlx_get_data_addr(bundle->img->image, &bundle->img->bpp,
			&bundle->img->sizeline, &bundle->img->endian);
	bundle->img->bpp /= 8;
	bundle_init(bundle);
	return (bundle);
}

int			catch_error(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_putendl("usage:/ one file needed");
		return (0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		ft_putendl("open() error");
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_bundle	*bundle;

	bundle = malloc(sizeof(t_bundle));
	if (!catch_error(argc, argv, &fd))
		return (0);
	if (!read_map(fd, &bundle->map))
	{
		ft_putendl("map error");
		return (0);
	}
	bundle = initiate(bundle);
	mlx_put_image_to_window(bundle->mlx, bundle->win, bundle->img->image, 0, 0);
	mlx_hook(bundle->win, 2, 0, key_press, &bundle);
	mlx_hook(bundle->win, 3, 0, key_release, &bundle);
	mlx_hook(bundle->win, 4, 0, mouse_click, &bundle);
	mlx_hook(bundle->win, 5, 0, mouse_release, &bundle);
	mlx_hook(bundle->win, 6, 0, mouse_move, &bundle);
	mlx_loop(bundle->mlx);
	return (0);
}
