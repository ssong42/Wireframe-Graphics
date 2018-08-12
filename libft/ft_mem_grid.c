/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:53:53 by ssong             #+#    #+#             */
/*   Updated: 2017/12/09 15:32:07 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		**ft_mem_grid(int row, int col)
{
	int i;
	int **grid;

	i = 0;
	grid = malloc((sizeof(int*)) * row);
	while (i < row)
	{
		grid[i] = malloc(sizeof(int) * col);
		i++;
	}
	return (grid);
}
