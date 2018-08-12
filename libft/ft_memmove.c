/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:49:07 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 16:04:51 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *d;
	char *s;

	s = (char*)src;
	d = (char*)dest;
	if (src == dest)
		return (dest);
	else if (src < dest)
	{
		s = (char*)src + len - 1;
		d = dest + len - 1;
		while (len-- > 0)
			*d-- = *s--;
	}
	else
		ft_memcpy(d, s, len);
	return (dest);
}
