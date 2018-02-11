/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:04:20 by ssong             #+#    #+#             */
/*   Updated: 2018/02/09 11:26:14 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include "mlx.h"
#include <math.h>
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
	double		x;
	double		y;
	double		z;
	int		color;
	double		w;
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
	double		x_width;
	double		y_length;
	double		scale;
}				t_map;

typedef struct	s_bundle
{
	void	*win;
	void	*mlx;
	t_mouse	*mouse;
	t_map	*map;
	t_image	*img;
	int		mousepressed;
	int		ctrlpressed;
	double	thetax;
	double	thetay;
	double	thetaz;
	double	thetapx;
	double	thetapy;
	double	thetapz;
	double	middle_x;
	double	middle_y;
	double	zoom;
	
}				t_bundle;

int				get_next_line(int fd, char **line);
int				ft_findwidth(char *line);
int				read_map(int fd, t_map **map);
int				mouse_release(int button, int x, int y, t_bundle **bundle);
int				mouse_move(int x, int y, t_bundle **bundle);
int				mouse_click(int button, int x, int y, t_bundle **bundle);
int				key_press(int button, t_bundle **bundle);
int				key_release(int button, t_bundle **bundle);
void			render(t_bundle *bundle);
t_bundle		*shift_trans(t_bundle *bundle);
t_bundle		*zoomin_trans(t_bundle *bundle);
t_bundle		*zoomout_trans(t_bundle *bundle);
void			new_image(t_bundle *bundle);
void			putpicture(t_map *map, t_image *img);
t_bundle		*rotate_x(t_bundle *bundle);
t_bundle		*rotate_y(t_bundle *bundle);
t_bundle		*rotate_z(t_bundle *bundle);
t_bundle		*converttocenter(t_bundle *bundle);
t_bundle		*converttocenter2(t_bundle *bundle);
t_bundle		*rotate_trans(t_bundle *bundle);
t_bundle		*converttocenterimage(t_bundle *bundle);
t_bundle		*portrayz(t_bundle *bundle);
t_bundle		*revportrayz(t_bundle *bundle);
t_bundle		*bresenham_leftright(t_bundle *bundle);

#endif
