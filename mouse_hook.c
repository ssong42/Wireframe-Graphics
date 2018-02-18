/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:15:43 by ssong             #+#    #+#             */
/*   Updated: 2018/02/17 10:38:07 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_release(int button, int x, int y, t_bundle **bundle)
{
	if (button == 1)
	{
		x = 1;
		y = 1;
		(*bundle)->mouse->prevx = 0;
		(*bundle)->mouse->prevy = 0;
		(*bundle)->mouse->x = 0;
		(*bundle)->mouse->y = 0;
		(*bundle)->mousepressed = 0;
	}
	return (0);
}

int		mouse_move(int x, int y, t_bundle **bundle)
{
	if ((*bundle)->mousepressed == 1 && (*bundle)->ctrlpressed == 1)
	{
		(*bundle)->mouse->prevx = (*bundle)->mouse->x;
		(*bundle)->mouse->prevy = (*bundle)->mouse->y;
		(*bundle)->mouse->x = x;
		(*bundle)->mouse->y = y;
		converttocenter2(*bundle);
		rotate_trans(*bundle);
		converttocenterimage(*bundle);
		new_image(*bundle);
	}
	else if ((*bundle)->mousepressed == 1)
	{
		(*bundle)->mouse->prevx = (*bundle)->mouse->x;
		(*bundle)->mouse->prevy = (*bundle)->mouse->y;
		(*bundle)->mouse->x = x;
		(*bundle)->mouse->y = y;
		shift_trans(*bundle);
		new_image(*bundle);
	}
	return (0);
}

int		mouse_click(int button, int x, int y, t_bundle **bundle)
{
	if (button == 1)
	{
		(*bundle)->mouse->x = x;
		(*bundle)->mouse->y = y;
		(*bundle)->mousepressed = 1;
	}
	if (button == 4)
	{
		converttocenter2(*bundle);
		(*bundle)->zoom = .9;
		zoomout_trans(*bundle);
		converttocenterimage(*bundle);
		new_image(*bundle);
	}
	if (button == 5)
	{
		converttocenter2(*bundle);
		(*bundle)->zoom = 1.1;
		zoomout_trans(*bundle);
		converttocenterimage(*bundle);
		new_image(*bundle);
	}
	return (0);
}

int		key_press(int button, t_bundle **bundle)
{
	if (button == 256)
		(*bundle)->ctrlpressed = 1;
	else if (button == 53)
		exit(0);
	return (0);
}

int		key_release(int button, t_bundle **bundle)
{
	if (button == 256)
	{
		(*bundle)->ctrlpressed = 0;
	}
	return (0);
}

/*
**	 button 1: right click
**	 button 2: left click
**	 button 4: scroll down [zoom out]
**	 button 5: scroll up [zoom in]
**	 button 6: scroll right
**	 button 7: scroll left
*/
