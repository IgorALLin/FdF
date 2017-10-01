/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:49:18 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/14 13:19:41 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == 0)
		return (0);
	i = 0;
	res = ft_strnew(len);
	if (res == 0)
		return (0);
	while (len != 0)
	{
		res[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (res);
}
