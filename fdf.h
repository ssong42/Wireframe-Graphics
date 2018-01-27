/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:04:20 by ssong             #+#    #+#             */
/*   Updated: 2018/01/27 12:57:07 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include "mlx.h"
#include <fcntl.h>
# define WIN_X	1220
# define WIN_Y	720

typedef struct	s_double
{
	char			*line;
	char			*str;
	int				count;
	int				lines;
	int				fd;
	struct s_double	*next;
}				t_double;

typedef struct	s_mouse
{
	int		x;
	int		y;
	int		prevx;
	int		prevy;
	int		init;
}				t_mouse;

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
}				t_lines;

typedef struct	s_map
{
	t_vertic	*vertices;
	int			x_width;
	int			y_length;
	int			scale;
}				t_map;

typedef struct	s_bundle
{
	void	*win;
	void	*mlx;
	t_mouse	*mouse;
	t_map	*map;
	t_image	*img;
	int		mousepressed;
	int		x;
	int		y;
}				t_bundle;

int				get_next_line(int fd, char **line);
int				ft_findwidth(char *line);
int				read_map(int fd, t_map **map);
int				mouse_release(int button, int x, int y, t_bundle **bundle);
int				mouse_move(int x, int y, t_bundle **bundle);
int				mouse_click(int button, int x, int y, t_bundle **bundle);
void			render(t_bundle *bundle);
t_bundle		*shift_trans(t_bundle *bundle);
void			new_image(t_bundle *bundle);
void			putpicture(t_map *map, t_image *img);
#endif
