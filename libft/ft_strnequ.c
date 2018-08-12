/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:47:54 by ssong             #+#    #+#             */
/*   Updated: 2018/02/26 13:38:10 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while ((s1[i] || s2[i]) && n > 0)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
			n--;
		}
		return (1);
	}
	return (0);
}
