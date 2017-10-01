/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:32:23 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/19 18:13:21 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint(int *line, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(line[i]);
		i++;
	}
}

void	ft_printint(int **mas, int size1, int size2)
{
	int		i;
	int		j;

	j = 0;
	if (size1 < 1 || size2 < 1)
		return ;
	while (j < size1)
	{
		i = 0;
		while (i < size2)
		{
			ft_putnbr(mas[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	ft_printmas(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j] != 0)
	{
		i = 0;
		while (str[j][i] != '\0')
		{
			write(1, &str[j][i], 1);
			i++;
		}
		j++;
	}
}
