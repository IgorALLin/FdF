/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:43:30 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/23 12:49:18 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numwords(char *s, char c)
{
	int		word;
	int		count;

	word = 0;
	count = 0;
	while (*s != '\0')
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			count++;
		}
		if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (count);
}
