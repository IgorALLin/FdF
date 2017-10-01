/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:16:57 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/19 18:18:18 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_creatint(int size, int d)
{
	int		*ret;
	int		i;

	if (size <= 0)
		return (NULL);
	i = 0;
	ret = (int*)malloc(sizeof(int) * size);
	while (i < size)
	{
		ret[i] = d;
		i++;
	}
	return (ret);
}
