/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 15:32:27 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 19:02:54 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw(t_data *data)
{
	t_pixels	*head;

	head = data->pixels;
	while (data->pixels)
	{
		if (data->pixels->left != NULL)
			ft_bresenham(data, data->pixels->left, data->pixels->curr);
		if (data->pixels->up != NULL)
			ft_bresenham(data, data->pixels->up, data->pixels->curr);
		data->pixels = data->pixels->next;
	}
	data->pixels = head;
}

int			ft_expose_hook(t_data *data)
{
	ft_draw(data);
	return (0);
}
