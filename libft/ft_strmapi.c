/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:45:43 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 18:24:47 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	int		i;
	char	*newstr;

	i = 0;
	if (s != NULL)
	{
		c = ft_strlen(s);
		if (s == NULL)
			return (0);
		newstr = (char*)malloc(sizeof(char) * (c + 1));
		if (newstr == NULL)
			return (0);
		while (s[i])
		{
			newstr[i] = f(i, s[i]);
			i++;
		}
		newstr[i] = 0;
		return (newstr);
	}
	return (0);
}
