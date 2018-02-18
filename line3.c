/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:55:16 by ssong             #+#    #+#             */
/*   Updated: 2018/02/17 11:01:14 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*drawdown(t_bundle *bundle)
{
	if (bundle->y[0] > bundle->y[1])
		ft_swap(&bundle->y[0], &bundle->y[1]);
	bundle->y[0]++;
	while (bundle->y[0] < bundle->y[1])
	{
		put_pixel(bundle);
		bundle->y[0]++;
	}
	return (bundle);
}

t_bundle	*draw_lines(t_bundle *bundle)
{
	if (bundle->dy == 0)
		drawright(bundle);
	else if (bundle->dx == 0)
		drawdown(bundle);
	else if (bundle->dy > 0 && bundle->dx > 0 && bundle->dx >= bundle->dy)
		drawline(bundle);
	else if (bundle->dy > 0 && bundle->dx > 0 && bundle->dx < bundle->dy)
		drawline1(bundle);
	else if (bundle->dy < 0 && bundle->dx > 0 && bundle->dx >= -(bundle->dy))
		drawline2(bundle);
	else if (bundle->dy < 0 && bundle->dx > 0 && bundle->dx < -(bundle->dy))
		drawline3(bundle);
	return (bundle);
}
