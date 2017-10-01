/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 15:55:50 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/26 15:55:52 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			draw_color(int c0, int c1, int d, int i)
{
	int r;
	int g;
	int b;

	r = ((c0 & 0xFF0000) >> 16) - ((((c0 & 0xFF0000) >> 16) -
		((c1 & 0xFF0000) >> 16)) * i / d);
	g = ((c0 & 0xFF00) >> 8) - ((((c0 & 0xFF00) >> 8) -
		((c1 & 0xFF00) >> 8)) * i / d);
	b = (c0 & 0xFF) - (((c0 & 0xFF) - (c1 & 0xFF)) * i / d);
	return ((r << 16) + (g << 8) + b);
}

static int	ft_add_rgb(int color, int flag)
{
	int		r;
	int		g;
	int		b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = color & 0xFF;
	if (flag == 1)
	{
		r += 5;
		r = r <= 255 ? r : r - 255;
	}
	else if (flag == 2)
	{
		g += 5;
		g = g <= 255 ? g : g - 255;
	}
	else
	{
		b += 5;
		b = b <= 255 ? b : b - 255;
	}
	return ((r << 16) + (g << 8) + b);
}

void		ft_rainbow(t_data *data, int color)
{
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		data->pixels->curr->color =
		ft_add_rgb(data->pixels->curr->color, color);
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}
