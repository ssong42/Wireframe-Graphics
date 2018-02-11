/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:49:51 by ssong             #+#    #+#             */
/*   Updated: 2018/02/10 17:55:00 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*put_pixel(int x, int y, t_bundle *bundle)
{
	*(int *)(bundle->img->ptr + (x * bundle->img->bpp +
				y * bundle->img->sizeline)) = 0x0000FF;
	return (bundle);
}

t_bundle *drawline(int *x, int *y, t_bundle *bundle)
{
	int dx;
	int dy;
	int dy_sum;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	x[0]++;
	dy_sum = dy;
	while (x[0] < x[1] - 1)
	{
		dy_sum += dy;
		if (dy_sum > dx)
		{
			y[0]++;
			dy_sum -= dx;
		}
		put_pixel(x[0], y[0], bundle);
		x[0]++;
	}
	return (bundle);
}


t_bundle *drawline1(int *x, int *y, t_bundle *bundle)
{
	int dx;
	int dy;
	int dx_sum;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	dx_sum = dx;
	y[0]++;
	while (y[0] < y[1] - 1)
	{
		dx_sum += dx;
		if (dx_sum > dy)
		{
			x[0]++;
			dx_sum -= dy;
		}
		put_pixel(x[0], y[0], bundle);
		y[0]++;
	}
	return (bundle);
}

t_bundle *drawline2(int *x, int *y, t_bundle *bundle)
{
	int dx;
	int dy;
	int dy_sum;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	dy_sum = dx;
	x[0]++;
	while (x[0] < x[1] - 1)
	{
		dy_sum += -(dy);
		if (dy_sum > dx)
		{
			y[0]--;
			dy_sum -= dx;
		}
		put_pixel(x[0], y[0], bundle);
		x[0]++;
	}
	return (bundle);
}

t_bundle *drawline3(int *x, int *y, t_bundle *bundle)
{
	int dx;
	int dy;
	int dx_sum;

	dx = x[1] - x[0];
	dy = y[1] - y[0];
	y[0]--;
	dx_sum = dx;
	while (y[0] > y[1] + 1)
	{
		dx_sum += dx;
		if (dx_sum > -(dy))
		{
			x[0]++;
			dx_sum += dy;
		}
		put_pixel(x[0], y[0], bundle);
		y[0]--;
	}
	return (bundle);
}

t_bundle *drawright(int *x, int *y, t_bundle *bundle)
{
	x[0]++;
	while (x[0] < x[1] - 1)
	{
		put_pixel(x[0], y[0], bundle);
		x[0]++;
	}
	return (bundle);
}

t_bundle *drawdown(int *x, int *y, t_bundle *bundle)
{
	if (y[0] > y[1])
		ft_swap(&y[0], &y[1]);
	y[0]++;
	while (y[0] < y[1] - 1)
	{
		put_pixel(x[0], y[0], bundle);
		y[0]++;
	}
	return (bundle);
}

// differences are necessary to know which axis to iterate by and to what direction.
// drawline0 (0 > m < 1)
// x++, y sometimes ++
// drawline1 (-1 > m < 0)
// x++, y sometimes --;
// drawline2 (m > 1)
// y++, x sometimes ++;
// drawline3 (m < -1)
// y--, x sometimes ++;


t_bundle *bresenham_leftright(t_bundle *bundle)
{
	int i;
	int x[2];
	int y[2];
	int	dx;
	int dy;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		if (i % (int)bundle->map->x_width < (int)bundle->map->x_width - 1)
		{
			x[0] = bundle->map->vertices[i].x;
			y[0] = bundle->map->vertices[i].y;
			x[1] = bundle->map->vertices[i + 1].x;
			y[1] = bundle->map->vertices[i + 1].y;
			dx = x[1] - x[0];
			dy = y[1] - y[0];
			if (dx < 0)
			{
				ft_swap(&x[0], &x[1]);
				ft_swap(&y[0], &y[1]);
				dx = x[1] - x[0];
				dy = y[1] - y[0];
			}	
			if (dy == 0)
				drawright(x, y, bundle);
			else if (dx == 0)
				drawdown(x, y, bundle);
			else if (dy > 0 && dx > 0 && dx > dy)
				drawline(x, y, bundle);
			else if (dy > 0 && dx > 0 && dx < dy)
				drawline1(x, y, bundle);
			else if (dy < 0 && dx > 0 && dx > -(dy))
				drawline2(x, y, bundle);
			else if (dy < 0 && dx > 0 && dx < -(dy))
				drawline3(x, y, bundle);
		}
		if (i / (int)bundle->map->x_width < (int)bundle->map->y_length - 1)
		{
			x[0] = bundle->map->vertices[i].x;
			y[0] = bundle->map->vertices[i].y;
			x[1] = bundle->map->vertices[i + (int)bundle->map->x_width].x;
			y[1] = bundle->map->vertices[i + (int)bundle->map->x_width].y;
			dx = x[1] - x[0];
			dy = y[1] - y[0];
			if (dx < 0)
			{
				ft_swap(&x[0], &x[1]);
				ft_swap(&y[0], &y[1]);
				dx = x[1] - x[0];
				dy = y[1] - y[0];
			}	
			if (dy == 0)
				drawright(x, y, bundle);
			else if (dx == 0)
				drawdown(x, y, bundle);
			else if (dy > 0 && dx > 0 && dx > dy)
				drawline(x, y, bundle);
			else if (dy > 0 && dx > 0 && dx < dy)
				drawline1(x, y, bundle);
			else if (dy < 0 && dx > 0 && dx > -(dy))
				drawline2(x, y, bundle);
			else if (dy < 0 && dx > 0 && dx < -(dy))
				drawline3(x, y, bundle);

		}
		i++;		
	}
	return (bundle);
}

// for every point it also needs to draw the line from top to bottom.
// Idk if this formula can handle when the slope is > 1 or > -1.
// It doesnt handle that yet cause it only iterates y one by one.
// 
// * m < 1 && m > 0 ~ finished.
// * m < 0 m + -1 
// * m > 1
// * m < -1
//
