/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:21:11 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 16:47:52 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int base;

	base = 1;
	if (n < 0)
		ft_putchar('-');
	while ((n / base) > 9 || (n / base) < -9)
		base = base * 10;
	while (base != 0)
	{
		if (n == 0)
			ft_putchar('0');
		else if (n > 0)
			ft_putchar((n / base) + '0');
		else
			ft_putchar((n / base) * -1 + '0');
		n = n % base;
		base = base / 10;
	}
}
