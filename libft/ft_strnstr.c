/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:45:14 by ssong             #+#    #+#             */
/*   Updated: 2017/12/09 13:13:50 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int n)
{
	int			i;
	const char	*tmp;

	if (*little == 0)
		return ((char*)big);
	while (*big && n)
	{
		i = 0;
		tmp = big;
		while (*tmp == little[i] && *tmp && little[i] && n - i > 0)
		{
			tmp++;
			i++;
		}
		if (little[i] == 0)
			return ((char*)big);
		big++;
		n--;
	}
	return (NULL);
}
