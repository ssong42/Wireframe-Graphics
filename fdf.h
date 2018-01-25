/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:04:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/25 14:25:07 by ssong            ###   ########.fr       */
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
}				t_graph;

typedef struct	s_vertic
{
	int		x;
	int		y;
	double	z;
	int		color;
	int		w;
}				t_vertic;

typedef struct	s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	color;
	int				dist;
}				t_image;

typedef struct	s_lines
{
	char			**num;
	int				y;
	struct s_lines	*next;
}					t_lines;

typedef struct	s_map
{
	t_vertic	*vertices;
	int			x_width;
	int			y_length;
}				t_map;

int				get_next_line(int fd, char **line);
void			convertodouble(t_map **map, t_lines *list);
void			malloctosize(t_map **map);
int				ft_findwidth(char *line);
int				read_map(int fd, t_map **map);
t_lines			*createlink();
t_lines			*addnmove(t_lines *list);
#endif
