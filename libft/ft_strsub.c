/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:59:31 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 18:18:48 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	if (s != NULL)
	{
		sub = (char*)malloc(sizeof(char) * (len + 1));
		if (sub == 0)
			return (0);
		while (len > 0)
		{
			sub[i] = s[start + i];
			i++;
			len--;
		}
		sub[i] = 0;
		return (sub);
	}
	return (0);
}
