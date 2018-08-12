/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:26:30 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 18:09:48 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	int		i;
	char	*newstr;

	i = 0;
	if (s != NULL)
	{
		c = ft_strlen(s);
		newstr = (char*)malloc(sizeof(char) * (c + 1));
		if (newstr == NULL)
			return (0);
		while (s[i])
		{
			newstr[i] = f(s[i]);
			i++;
		}
		newstr[i] = 0;
		return (newstr);
	}
	return (NULL);
}
