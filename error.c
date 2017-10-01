/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:01:55 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 19:02:19 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putstr("error reading file\n");
		exit(0);
	}
	if (error == 2)
	{
		ft_putstr("wrong input format\n");
		exit(0);
	}
	if (error == 3)
	{
		ft_putstr("error opening file\n");
		exit(0);
	}
}
