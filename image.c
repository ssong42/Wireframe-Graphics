/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:17:21 by ssong             #+#    #+#             */
/*   Updated: 2018/02/05 18:54:24 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_image *img)
{
	ft_bzero(img->ptr, (WIN_X * WIN_Y * img->bpp)); 
}

void	new_image(t_bundle *bundle)
{
	clear_img(bundle->img);
	putpicture(bundle->map, bundle->img);
	mlx_put_image_to_window(bundle->mlx, bundle->win,
			bundle->img->image, 0, 0);
}
