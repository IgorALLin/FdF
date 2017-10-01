/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:56:42 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/07 13:10:26 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (src[count] != '\0')
		count++;
	str = (char*)malloc(sizeof(char) * count + 1);
	if (str == 0)
		return (0);
	while (i < count)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
