/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:51:36 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/14 13:16:57 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;

	if (s2 == 0 || s1 == 0)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_strnew(len + 1);
	if (res == 0)
		return (0);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}
