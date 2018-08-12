/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:19:33 by ssong             #+#    #+#             */
/*   Updated: 2018/02/17 10:54:25 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*drawline(t_bundle *bundle)
{
	int dy_sum;

	bundle->x[0]++;
	dy_sum = bundle->dy;
	while (bundle->x[0] < bundle->x[1])
	{
		dy_sum += bundle->dy;
		if (dy_sum >= bundle->dx)
		{
			bundle->y[0]++;
			dy_sum -= bundle->dx;
		}
		put_pixel(bundle);
		bundle->x[0]++;
	}
	return (bundle);
}

t_bundle	*drawline1(t_bundle *bundle)
{
	int dx_sum;

	dx_sum = bundle->dx;
	bundle->y[0]++;
	while (bundle->y[0] < bundle->y[1])
	{
		dx_sum += bundle->dx;
		if (dx_sum > bundle->dy)
		{
			bundle->x[0]++;
			dx_sum -= bundle->dy;
		}
		put_pixel(bundle);
		bundle->y[0]++;
	}
	return (bundle);
}

t_bundle	*drawline2(t_bundle *bundle)
{
	int dy_sum;

	dy_sum = bundle->dy;
	bundle->x[0]++;
	while (bundle->x[0] < bundle->x[1])
	{
		dy_sum += bundle->dy;
		if (-dy_sum >= bundle->dx)
		{
			bundle->y[0]--;
			dy_sum += bundle->dx;
		}
		put_pixel(bundle);
		bundle->x[0]++;
	}
	return (bundle);
}

t_bundle	*drawline3(t_bundle *bundle)
{
	int dx_sum;

	bundle->y[0]--;
	dx_sum = bundle->dx;
	while (bundle->y[0] > bundle->y[1])
	{
		dx_sum += bundle->dx;
		if (dx_sum > -(bundle->dy))
		{
			bundle->x[0]++;
			dx_sum += bundle->dy;
		}
		put_pixel(bundle);
		bundle->y[0]--;
	}
	return (bundle);
}

t_bundle	*drawright(t_bundle *bundle)
{
	bundle->x[0]++;
	while (bundle->x[0] < bundle->x[1])
	{
		put_pixel(bundle);
		bundle->x[0]++;
	}
	return (bundle);
}
