/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:59:49 by ssong             #+#    #+#             */
/*   Updated: 2018/02/17 16:40:28 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*shift_trans(t_bundle *bundle)
{
	int i;

	i = 0;
	if (bundle->mouse->x != bundle->mouse->prevx
			|| bundle->mouse->y != bundle->mouse->prevy)
	{
		while (i < (bundle->map->x_width * bundle->map->y_length))
		{
			if (bundle->mouse->x != bundle->mouse->prevx)
				bundle->map->vertices[i].x -=
					(bundle->mouse->prevx - bundle->mouse->x);
			if (bundle->mouse->y != bundle->mouse->prevy)
				bundle->map->vertices[i].y -=
					(bundle->mouse->prevy - bundle->mouse->y);
			i++;
		}
	}
	return (bundle);
}

t_bundle	*zoomout_trans(t_bundle *bundle)
{
	int i;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		bundle->map->vertices[i].x *= bundle->zoom;
		bundle->map->vertices[i].y *= bundle->zoom;
		bundle->map->vertices[i].z *= bundle->zoom;
		i++;
	}
	return (bundle);
}

t_bundle	*zoomin_trans(t_bundle *bundle)
{
	int i;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		bundle->map->vertices[i].x *= bundle->zoom;
		bundle->map->vertices[i].y *= bundle->zoom;
		bundle->map->vertices[i].z *= bundle->zoom;
		i++;
	}
	return (bundle);
}

t_bundle	*converttocenterimage(t_bundle *bundle)
{
	int i;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		bundle->map->vertices[i].x += WIN_X / 2;
		bundle->map->vertices[i].y += WIN_Y / 2;
		i++;
	}
	return (bundle);
}

t_bundle	*converttocenter2(t_bundle *bundle)
{
	int i;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		bundle->map->vertices[i].x -= WIN_X / 2;
		bundle->map->vertices[i].y -= WIN_Y / 2;
		i++;
	}
	return (bundle);
}
