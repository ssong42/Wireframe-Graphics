/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:04:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/20 15:50:06 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include "mlx.h"
#include <fcntl.h>

typedef struct	s_double
{
	char			*line;
	char			*str;
	int				count;
	int				lines;
	int				fd;
	struct s_double	*next;
}				t_double;

typedef struct	s_graph
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_graph;

typedef struct	s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_image;

typedef struct	s_lines
{
	char			**num;
	struct s_lines	*next;
}					t_lines;

typedef struct	s_map
{
	double	**map;
	int		x_width;
	int		y_length;

}				t_map;
int				get_next_line(int fd, char **line);
#endif
