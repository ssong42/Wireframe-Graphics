/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:40:38 by ssong             #+#    #+#             */
/*   Updated: 2017/12/01 18:22:31 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		a;

	i = 0;
	a = 0;
	i = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (i + 1));
	if (s2 == 0)
		return (NULL);
	while (a < i)
	{
		s2[a] = s1[a];
		a++;
	}
	s2[a] = 0;
	return ((char*)s2);
}
