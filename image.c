/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:17:21 by ssong             #+#    #+#             */
/*   Updated: 2018/03/07 11:28:04 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clear_img(t_image *img)
{
	ft_bzero(img->ptr, (WIN_X * WIN_Y * img->bpp));
}

void		new_image(t_bundle *bundle)
{
	clear_img(bundle->img);
	ddalines(bundle);
	putpicture(bundle->map, bundle->img);
	mlx_put_image_to_window(bundle->mlx, bundle->win,
			bundle->img->image, 0, 0);
}

t_bundle	*put_pixel(t_bundle *bundle)
{
	if (bundle->x[0] < WIN_X && bundle->x[0] >= 0
			&& bundle->y[0] < WIN_Y && bundle->y[0] >= 0)
	{
		if (bundle->dz[0] > 0 || bundle->dz[0] < 0)
			*(int *)(bundle->img->ptr + (bundle->x[0] * bundle->img->bpp +
				bundle->y[0] * bundle->img->sizeline)) = 0x0000FF;
		else if (!bundle->dz[0] && !bundle->dz[1])
			*(int *)(bundle->img->ptr + (bundle->x[0] * bundle->img->bpp +
				bundle->y[0] * bundle->img->sizeline)) = 0x00FF00;
		else if (!bundle->dz[0] && bundle->dz[1])
			*(int *)(bundle->img->ptr + (bundle->x[0] * bundle->img->bpp +
				bundle->y[0] * bundle->img->sizeline)) = 0xFF0000;
	}
	return (bundle);
}

void		putpicture(t_map *map, t_image *img)
{
	int i;

	i = 0;
	while (i < (map->x_width * map->y_length))
	{
		if (map->vertices[i].x < WIN_X && map->vertices[i].x >= 0)
			if (map->vertices[i].y < WIN_Y && map->vertices[i].y >= 0)
				*(int *)(img->ptr + ((int)map->vertices[i].x * img->bpp + ((int)map->vertices[i].y * img->sizeline))) = map->vertices[i].color;
		i++;
	}
}
