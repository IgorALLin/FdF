/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:58:41 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/12 18:33:21 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int				count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (dst[count] != '\0')
		count++;
	while (src[i] != '\0' && (i < n))
	{
		dst[count] = src[i];
		i++;
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
