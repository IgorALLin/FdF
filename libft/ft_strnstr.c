/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:52:46 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/14 17:52:51 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*tmp_b;
	char	*tmp_l;
	int		buf_len;
	int		i;

	i = len;
	if (*little == 0)
		return ((char*)big);
	while (*big && i >= 0)
	{
		tmp_b = (char*)big;
		tmp_l = (char*)little;
		buf_len = i;
		while (*big && *little && *big == *tmp_l && i > 0)
		{
			big++;
			tmp_l++;
			i--;
		}
		if (*tmp_l == 0)
			return (tmp_b);
		i = buf_len - 1;
		big = tmp_b + 1;
	}
	return (0);
}
