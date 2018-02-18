/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:52:35 by ssong             #+#    #+#             */
/*   Updated: 2018/02/17 16:42:17 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bundle	*rotate_trans(t_bundle *bundle)
{
	if (bundle->mouse->x > bundle->mouse->prevx)
	{
		bundle->thetapy = bundle->thetay;
		bundle->thetay += .1;
		rotate_y(bundle);
	}
	else if (bundle->mouse->x < bundle->mouse->prevx)
	{
		bundle->thetapy = bundle->thetay;
		bundle->thetay -= .1;
		rotate_y(bundle);
	}
	if (bundle->mouse->y > bundle->mouse->prevy)
	{
		bundle->thetapx = bundle->thetax;
		bundle->thetax -= .1;
		rotate_x(bundle);
	}
	else if (bundle->mouse->y < bundle->mouse->prevy)
	{
		bundle->thetapx = bundle->thetax;
		bundle->thetax += .1;
		rotate_x(bundle);
	}
	return (bundle);
}

t_bundle	*rotate_x(t_bundle *bundle)
{
	int		i;
	double	cos_yz;
	double	sin_yz;
	double	y;
	double	z;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		y = bundle->map->vertices[i].y;
		z = bundle->map->vertices[i].z;
		cos_yz = y * cos(bundle->thetax - bundle->thetapx);
		sin_yz = z * sin(bundle->thetax - bundle->thetapx);
		bundle->map->vertices[i].y = cos_yz - sin_yz;
		cos_yz = y * sin(bundle->thetax - bundle->thetapx);
		sin_yz = z * cos(bundle->thetax - bundle->thetapx);
		bundle->map->vertices[i].z = cos_yz + sin_yz;
		i++;
	}
	return (bundle);
}

t_bundle	*rotate_y(t_bundle *bundle)
{
	int		i;
	double	cos_xz;
	double	sin_xz;
	double	x;
	double	z;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		x = bundle->map->vertices[i].x;
		z = bundle->map->vertices[i].z;
		cos_xz = z * cos(bundle->thetay - bundle->thetapy);
		sin_xz = x * sin(bundle->thetay - bundle->thetapy);
		bundle->map->vertices[i].z = cos_xz - sin_xz;
		cos_xz = x * cos(bundle->thetay - bundle->thetapy);
		sin_xz = z * sin(bundle->thetay - bundle->thetapy);
		bundle->map->vertices[i].x = sin_xz + cos_xz;
		i++;
	}
	return (bundle);
}

t_bundle	*rotate_z(t_bundle *bundle)
{
	int		i;
	double	cos_xy;
	double	sin_xy;
	double	x;
	double	y;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		x = bundle->map->vertices[i].x;
		y = bundle->map->vertices[i].y;
		cos_xy = x * cos(bundle->thetaz);
		sin_xy = y * sin(bundle->thetaz);
		bundle->map->vertices[i].x = cos_xy + sin_xy;
		cos_xy = y * cos(bundle->thetaz);
		sin_xy = x * sin(bundle->thetaz);
		bundle->map->vertices[i].y = -sin_xy + cos_xy;
		i++;
	}
	return (bundle);
}

t_bundle	*converttocenter(t_bundle *bundle)
{
	int i;

	i = 0;
	while (i < (bundle->map->x_width * bundle->map->y_length))
	{
		bundle->map->vertices[i].x -= bundle->middle_x;
		bundle->map->vertices[i].y -= bundle->middle_y;
		i++;
	}
	return (bundle);
}
