/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:41:18 by ichebota          #+#    #+#             */
/*   Updated: 2016/11/29 13:58:08 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (dst[count] != '\0')
		count++;
	while (src[i] != '\0')
	{
		dst[count] = src[i];
		count++;
		i++;
	}
	dst[count] = '\0';
	return (dst);
}
