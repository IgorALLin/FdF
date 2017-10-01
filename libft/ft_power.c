/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:51:13 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/19 17:51:15 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int num, int pow)
{
	int		res;

	if (pow == 0)
		return (1);
	if (num == 0 || pow < 0)
		return (0);
	if (pow == 1)
		return (num);
	res = num;
	while (pow != 1)
	{
		res = res + num * pow;
		pow--;
	}
	return (res);
}
