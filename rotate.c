/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:13:04 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 18:53:24 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_rotate_z(t_data *data, int a)
{
	double		bx;
	double		by;
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		bx = data->pixels->curr->x;
		by = data->pixels->curr->y;
		data->pixels->curr->x = bx * cos(a * 3.14 / 180)
		- by * sin(a * 3.14 / 180);
		data->pixels->curr->y = bx * sin(a * 3.14 / 180)
		+ by * cos(a * 3.14 / 180);
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}

static	void	ft_rotate_y(t_data *data, int a)
{
	double		bz;
	double		bx;
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		bx = data->pixels->curr->x;
		bz = data->pixels->curr->z;
		data->pixels->curr->x = bx * cos(a * 3.14 / 180)
		+ bz * sin(a * 3.14 / 180);
		data->pixels->curr->z = bx * sin(a * 3.14 / 180) * (-1)
		+ bz * cos(a * 3.14 / 180);
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}

static	void	ft_rotate_x(t_data *data, int a)
{
	double		bz;
	double		by;
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		by = data->pixels->curr->y;
		bz = data->pixels->curr->z;
		data->pixels->curr->y = by * cos(a * 3.14 / 180)
		- bz * sin(a * 3.14 / 180);
		data->pixels->curr->z = by * sin(a * 3.14 / 180)
		+ bz * cos(a * 3.14 / 180);
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}

void			ft_rotate(t_data *data, int x, int y, int z)
{
	ft_rotate_x(data, x);
	ft_rotate_y(data, y);
	ft_rotate_z(data, z);
}
