/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:07:39 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 18:51:35 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_controls(void)
{
	ft_putstr("______________________________________________");
	ft_putstr("\n\t\tCONTROL PANEL:\n");
	ft_putstr("______________________________________________");
	ft_putstr("\n\n\t\tRotate image:\n");
	ft_putstr("\t\t_______________\n\n");
	ft_putstr(">> OX:\t\tW, S\n>> OY:\t\tA, D\n>> OZ:\t\tQ, E\n\n");
	ft_putstr("\n\t\tMove image:\n");
	ft_putstr("\t\t_______________\n\n");
	ft_putstr(">> Righr:\tRighr arrow\n>> Left:\tLeft arrow\n");
	ft_putstr(">> Up:\t\tUp arrow\n>> Down:\tDown arrow\n");
	ft_putstr(">> Center img:\t0\n\n");
	ft_putstr("\n\t\tZoom image:\n");
	ft_putstr("\t\t_______________\n\n");
	ft_putstr(">> Zoom + :\t+\n>> Zoom - :\t-\n");
	ft_putstr(">> Zoom ++ :\t*\n>> Zoom -- :\t/\n");
	ft_putstr("\n\t\tAdd RGB:\n");
	ft_putstr("\t\t_______________\n\n");
	ft_putstr(">> Red + :\tR\n");
	ft_putstr(">> Green + :\tG\n");
	ft_putstr(">> Blue + :\tB\n");
	ft_putstr("______________________________________________\n");
}

t_data	*ft_creat_data(char *argv)
{
	t_data	*data;
	char	c;
	int		fd;

	data = (t_data *)malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W, H, "FdF");
	data->ysize = 0;
	data->mvx = 0;
	data->mvy = 0;
	if ((fd = open(argv, O_DIRECTORY)) >= 0)
		ft_error(1);
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error(1);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			data->ysize++;
	}
	close(fd);
	data->mvx = 0;
	data->mvy = 0;
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc != 2)
		ft_error(3);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	data = ft_creat_data(argv[1]);
	ft_controls();
	ft_read(data, fd);
	ft_new_size(data);
	ft_rotate(data, 30, -15, 5);
	ft_put_to_center(data);
	mlx_hook(data->win, 2, 5, key_funct, data);
	mlx_expose_hook(data->win, ft_expose_hook, data);
	mlx_loop(data->mlx);
}
