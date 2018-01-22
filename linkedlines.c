/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:08:11 by ssong             #+#    #+#             */
/*   Updated: 2018/01/21 18:10:24 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lines	*createlink()
{
	t_lines *list;

	list = malloc(sizeof(t_lines));
	list->next = NULL;
	return (list);
}

t_lines	*addnmove(t_lines *list)
{
	t_lines *new;
	new = createlink();
	list->next = new;
	list = list->next;
	return (list);	
}
