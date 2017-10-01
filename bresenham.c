/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 15:38:53 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/26 15:38:54 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_vertical(t_data *data, t_pixel *p0, t_pixel *p1, t_draw draw)
{
	int		x;
	int		y;
	int		i;

	mlx_pixel_put(data->mlx, data->win, p0->x, p0->y, p0->color);
	x = p0->x;
	y = p0->y + draw.sy;
	i = 1;
	while (i <= draw.dy)
	{
		if (draw.d > 0)
		{
			draw.d += draw.d2;
			x += draw.sx;
		}
		else
			draw.d += draw.d1;
		mlx_pixel_put(data->mlx, data->win, x, y, draw_color(p0->color,
			p1->color, draw.dy, i));
		i++;
		y += draw.sy;
	}
}

static void	ft_horizontal(t_data *data, t_pixel *p0, t_pixel *p1, t_draw draw)
{
	int		x;
	int		y;
	int		i;

	mlx_pixel_put(data->mlx, data->win, p0->x, p0->y, p0->color);
	x = p0->x + draw.sx;
	y = p0->y;
	i = 1;
	while (i <= draw.dx)
	{
		if (draw.d > 0)
		{
			draw.d += draw.d2;
			y += draw.sy;
		}
		else
			draw.d += draw.d1;
		mlx_pixel_put(data->mlx, data->win, x, y,
			draw_color(p0->color, p1->color, draw.dx, i));
		i++;
		x += draw.sx;
	}
}

void		ft_bresenham(t_data *data, t_pixel *p0, t_pixel *p1)
{
	t_draw	draw;

	draw.dx = fabs(p1->x - p0->x);
	draw.dy = fabs(p1->y - p0->y);
	draw.sx = p1->x >= p0->x ? 1 : -1;
	draw.sy = p1->y >= p0->y ? 1 : -1;
	if (draw.dy <= draw.dx)
	{
		draw.d = (draw.dy << 1) - draw.dx;
		draw.d1 = draw.dy << 1;
		draw.d2 = (draw.dy - draw.dx) << 1;
		ft_horizontal(data, p0, p1, draw);
	}
	else
	{
		draw.d = (draw.dx << 1) - draw.dy;
		draw.d1 = draw.dx << 1;
		draw.d2 = (draw.dx - draw.dy) << 1;
		ft_vertical(data, p0, p1, draw);
	}
}
