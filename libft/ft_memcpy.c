/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:48:37 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/12 17:49:05 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*res1;
	char	*res2;

	res1 = (char*)dest;
	res2 = (char*)src;
	i = 0;
	while (n != 0)
	{
		res1[i] = res2[i];
		i++;
		n--;
	}
	return (dest);
}
