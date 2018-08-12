/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:45:13 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 16:06:03 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	if (little[i] == 0)
		return ((char*)big);
	while (big[c])
	{
		i = 0;
		j = c;
		while (big[j] == little[i] && big[j] != 0 && little[i] != 0)
		{
			i++;
			j++;
		}
		if (little[i] == 0)
			return ((char*)(big + c));
		c++;
	}
	return (0);
}
