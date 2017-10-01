/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:00:18 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 19:01:51 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_color(int keycode, t_data *data)
{
	if (keycode == 15)
		ft_rainbow(data, 1);
	else if (keycode == 5)
		ft_rainbow(data, 2);
	else if (keycode == 11)
		ft_rainbow(data, 3);
}

static void		ft_size(int keycode, t_data *data)
{
	if (keycode == 69)
		ft_zoom(data, 1.01);
	else if (keycode == 78)
		ft_zoom(data, 0.99);
	else if (keycode == 67)
		ft_zoom(data, 2);
	else if (keycode == 75)
		ft_zoom(data, 0.5);
}

static void		ft_move(int keycode, t_data *data)
{
	if (keycode == 125)
		ft_moving(data, 0, 10);
	else if (keycode == 126)
		ft_moving(data, 0, -10);
	else if (keycode == 124)
		ft_moving(data, 1, 10);
	else if (keycode == 123)
		ft_moving(data, 1, -10);
	else if (keycode == 82)
		ft_moving(data, 2, 0);
}

static void		ft_hook_rotate(int keycode, t_data *data)
{
	if (keycode == 14)
		ft_rotate(data, 0, 0, 2);
	else if (keycode == 13)
		ft_rotate(data, 2, 0, 0);
	else if (keycode == 12)
		ft_rotate(data, 0, 0, -2);
	else if (keycode == 2)
		ft_rotate(data, 0, 2, 0);
	else if (keycode == 1)
		ft_rotate(data, -2, 0, 0);
	else if (keycode == 0)
		ft_rotate(data, 0, -2, 0);
}

int				key_funct(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	mlx_clear_window(data->mlx, data->win);
	ft_move(keycode, data);
	ft_hook_rotate(keycode, data);
	ft_size(keycode, data);
	ft_color(keycode, data);
	ft_put_to_center(data);
	ft_draw(data);
	return (0);
}
