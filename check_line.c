/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 21:00:46 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 19:07:11 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_hex(char *line, int i)
{
	int		in;

	in = 6;
	i += 3;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] == ' ')
			break ;
		if (((line[i] < 'A' && line[i] > 'F') &&
			(line[i] < 'a' && line[i] > 'f') &&
			ft_isdigit(line[i]) == 0) || in < 0)
			return (-1);
		i++;
		in--;
	}
	if (line[i] == '\0')
		return (i);
	return (i + 1);
}

void	ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (ft_isdigit(line[i - 1]) && line[i] == ',' && line[i + 1] == '0' &&
				line[i + 2] == 'x' && line[i + 3] != ' ')
			i = ft_check_hex(line, i + 1);
		if (i == -1)
			ft_error(2);
		if (line[i] == '\0')
			break ;
		if (line[i] == '-' || ft_isdigit(line[i]) == 1)
			i++;
		else
			ft_error(2);
	}
}
