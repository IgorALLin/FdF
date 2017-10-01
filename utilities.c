/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 15:01:14 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/30 20:00:28 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_add_color(char *pic, int z)
{
	int		color;

	while (*pic)
	{
		if (*pic == ',')
			return (ft_atoi_base(pic += 3, 16));
		pic++;
	}
	if (z <= 0)
		color = 0x0D6386;
	else if (z > 0 && z <= 10)
		color = 0x32A862;
	else if (z > 10 && z <= 20)
		color = 0x8FC89A;
	else if (z > 20 && z <= 50)
		color = 0xFAECBE;
	else if (z > 50 && z <= 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xF8F8FF;
	else
		color = 0;
	return (color);
}

void		ft_moving(t_data *data, int v, int val)
{
	if (v == 2)
	{
		data->mvx = 0;
		data->mvy = 0;
	}
	if (v == 1)
		data->mvx += val;
	if (v == 0)
		data->mvy += val;
}

void		ft_zoom(t_data *data, double val)
{
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		data->pixels->curr->x *= val;
		data->pixels->curr->y *= val;
		data->pixels->curr->z *= val;
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}

void		ft_new_size(t_data *data)
{
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		data->pixels->curr->x *= S;
		data->pixels->curr->y *= S;
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}
