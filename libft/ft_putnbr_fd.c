/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:48:31 by ssong             #+#    #+#             */
/*   Updated: 2017/12/06 16:52:18 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int base;

	base = 1;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while ((n / base) > 9 || (n / base) < -9)
		base = base * 10;
	while (base != 0)
	{
		if (n == 0)
			ft_putchar_fd('0', fd);
		else if (n > 0)
			ft_putchar_fd((n / base) + '0', fd);
		else
			ft_putchar_fd((n / base) * -1 + '0', fd);
		n = n % base;
		base = base / 10;
	}
}
