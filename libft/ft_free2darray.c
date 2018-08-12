/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:10:46 by ssong             #+#    #+#             */
/*   Updated: 2018/02/17 16:20:51 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free2darray(char **longmap, int x, int y)
{
	int i;

	i = 0;
	while (i < (x * y))
	{
		free(longmap[i]);
		i++;
	}
}