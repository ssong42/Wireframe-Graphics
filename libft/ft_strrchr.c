/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:12:52 by ssong             #+#    #+#             */
/*   Updated: 2017/12/08 11:19:33 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i--;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
	return (NULL);
}
