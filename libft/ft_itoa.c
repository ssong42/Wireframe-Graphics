/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:24:17 by ssong             #+#    #+#             */
/*   Updated: 2018/01/10 16:37:31 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*str;
	size_t	c;
	size_t	neg;

	neg = 1;
	c = ft_countdigits(n);
	str = ft_strnew(c);
	if (!str)
		return (NULL);
	str[c] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			neg = -1;
		}
		str[c - 1] = ((n % 10) * neg) + '0';
		n = (n / 10);
		c--;
	}
	return (str);
}
