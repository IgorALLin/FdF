/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:08:07 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 19:18:41 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibX/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>

# define BUFF_SIZE 1
# define S 5
# define W 1800
# define H 900

typedef struct		s_center
{
	double			xmax;
	double			ymax;
	double			xmin;
	double			ymin;
	double			difx;
	double			dify;
}					t_center;

typedef struct		s_draw
{
	int				d;
	int				d1;
	int				d2;
	int				sx;
	int				sy;
	int				dx;
	int				dy;
}					t_draw;

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_pixel;

typedef struct		s_pixels
{
	t_pixel			*curr;
	t_pixel			*left;
	t_pixel			*up;
	struct s_pixels	*bufup;
	struct s_pixels	*last;
	struct s_pixels	*next;
}					t_pixels;

typedef struct		s_data
{
	void			*win;
	void			*mlx;
	int				ysize;
	int				*len;
	t_pixels		*pixels;
	int				mvx;
	int				mvy;
}					t_data;

int					get_next_line(const int fd, char **line);
void				ft_error(int error);
void				ft_put_to_center(t_data *data);
void				ft_read(t_data *data, int fd);
void				ft_rotate(t_data *data, int x, int y, int z);
void				ft_new_size(t_data *data);
void				ft_zoom(t_data *data, double val);
int					key_funct(int keycode, t_data *data);
void				ft_draw(t_data *data);
int					ft_expose_hook(t_data *data);
void				ft_bresenham(t_data *data, t_pixel *pix0, t_pixel *pix1);
int					draw_color(int c0, int c1, int d, int k);
void				ft_moving(t_data *data, int v, int val);
void				ft_put_to_center(t_data *data);
void				ft_check_line(char *line);
void				ft_rainbow(t_data *data, int color);
int					ft_add_color(char *pic, int z);

#endif
