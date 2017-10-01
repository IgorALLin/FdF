/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:51:49 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 19:05:07 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_center	ft_finde_difs(t_data *data)
{
	t_center	center;
	t_pixels	*head;

	center.xmax = data->pixels->curr->x;
	center.xmin = data->pixels->curr->x;
	center.ymax = data->pixels->curr->y;
	center.ymin = data->pixels->curr->y;
	head = data->pixels;
	while (data->pixels)
	{
		if (data->pixels->curr->x > center.xmax)
			center.xmax = data->pixels->curr->x;
		if (data->pixels->curr->x < center.xmin)
			center.xmin = data->pixels->curr->x;
		if (data->pixels->curr->y > center.ymax)
			center.ymax = data->pixels->curr->y;
		if (data->pixels->curr->y < center.ymin)
			center.ymin = data->pixels->curr->y;
		data->pixels = data->pixels->next;
	}
	center.difx = (W - fabs(center.xmax - center.xmin)) / 2;
	center.dify = (H - fabs(center.ymax - center.ymin)) / 2;
	data->pixels = head;
	return (center);
}

void		ft_put_to_center(t_data *data)
{
	t_pixels	*head;
	t_center	center;

	center = ft_finde_difs(data);
	head = data->pixels;
	while (data->pixels)
	{
		data->pixels->curr->x += (center.difx - center.xmin + data->mvx);
		data->pixels->curr->y += (center.dify - center.ymin + data->mvy);
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}
