/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:46:20 by ssong             #+#    #+#             */
/*   Updated: 2017/12/09 15:36:13 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_revwhite(char *str, int c)
{
	while (c > 0 && (str[c] == ' ' || str[c] == '\r'
				|| str[c] == '\t' || str[c] == '\n'))
		c--;
	return (c);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		c;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		c = ft_strlen((char*)s);
		i = ft_iswhite((char*)s);
		c = is_revwhite((char*)s, c - 1);
		if (c > 0)
			tmp = (char*)malloc(sizeof(char) * (c - i + 2));
		else
			tmp = (char*)malloc(sizeof(char) * (1));
		if (tmp == 0)
			return (0);
		while (i <= c)
			tmp[j++] = s[i++];
		tmp[j] = 0;
		return (tmp);
	}
	return (0);
}
