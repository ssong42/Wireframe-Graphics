/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:49:51 by ssong             #+#    #+#             */
/*   Updated: 2018/02/26 15:34:07 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*store_leftright(t_bundle *bundle)
{
	bundle->x[0] = bundle->map->vertices[bundle->i].x;
	bundle->y[0] = bundle->map->vertices[bundle->i].y;
	bundle->x[1] = bundle->map->vertices[bundle->i + 1].x;
	bundle->y[1] = bundle->map->vertices[bundle->i + 1].y;
	bundle->dz[0] = bundle->map->vertices[bundle->i].ogz
		- bundle->map->vertices[bundle->i + 1].ogz;
	if (bundle->map->vertices[bundle->i].ogz > 0
			|| bundle->map->vertices[bundle->i].ogz < 0)
		bundle->dz[1] = 1;
	return (bundle);
}

t_bundle	*store_updown(t_bundle *bundle)
{
	bundle->x[0] = bundle->map->vertices[bundle->i].x;
	bundle->y[0] = bundle->map->vertices[bundle->i].y;
	bundle->x[1] = bundle->map->vertices[bundle->i
		+ (int)bundle->map->x_width].x;
	bundle->y[1] = bundle->map->vertices[bundle->i
		+ (int)bundle->map->x_width].y;
	bundle->dz[0] = bundle->map->vertices[bundle->i].ogz
		- bundle->map->vertices[bundle->i + (int)bundle->map->x_width].ogz;
	if (bundle->map->vertices[bundle->i].ogz > 0
			|| bundle->map->vertices[bundle->i].ogz < 0)
		bundle->dz[1] = 1;
	return (bundle);
}

t_bundle	*store_deltas(t_bundle *bundle)
{
	bundle->dx = bundle->x[1] - bundle->x[0];
	bundle->dy = bundle->y[1] - bundle->y[0];
	if (bundle->dx < 0)
	{
		ft_swap(&bundle->x[0], &bundle->x[1]);
		ft_swap(&bundle->y[0], &bundle->y[1]);
		bundle->dx = bundle->x[1] - bundle->x[0];
		bundle->dy = bundle->y[1] - bundle->y[0];
	}
	return (bundle);
}

t_bundle	*ddalines(t_bundle *bundle)
{
	bundle->i = 0;
	while (bundle->i < (bundle->map->x_width
				* bundle->map->y_length))
	{
		bundle->dz[1] = 0;
		if (bundle->i % (int)bundle->map->x_width
				< (int)bundle->map->x_width - 1)
		{
			store_leftright(bundle);
			store_deltas(bundle);
			draw_lines(bundle);
		}
		if (bundle->i / (int)bundle->map->x_width
				< (int)bundle->map->y_length - 1)
		{
			store_updown(bundle);
			store_deltas(bundle);
			draw_lines(bundle);
		}
		bundle->i++;
	}
	return (bundle);
}

/*
** digital differential analyzer (DDA)
*/
