/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:58:01 by ichebota          #+#    #+#             */
/*   Updated: 2017/08/08 12:56:57 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_25strings(char *str)
{
	ft_strdel(&str);
	return (0);
}

int		ft_ret(int fd, int *rd, char *str)
{
	if (fd == -1 || read(fd, str, 0) == -1)
	{
		*rd = -1;
		return (-1);
	}
	if (!str && rd == 0)
	{
		*rd = 0;
		return (0);
	}
	*rd = 1;
	return (1);
}

char	*ft_next(char *tmp, char *str, char *ptr, char **line)
{
	char	*buf;
	char	*tm;

	if (ptr)
		*ptr = '\0';
	buf = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	tmp = buf;
	if (!ptr)
		ft_strdel(&str);
	if (ptr)
	{
		*line = tmp;
		tm = ft_strdup(ptr + 1);
		free(str);
		return (tm);
	}
	return (tmp);
}

char	*ft_newstr(int *rd, int fd, char *str)
{
	if (!str)
	{
		str = ft_strnew(BUFF_SIZE);
		*rd = read(fd, str, BUFF_SIZE);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*tmp;
	int			rd;

	if (ft_ret(fd, &rd, str) <= 0)
		return (rd);
	tmp = ft_strnew(0);
	while (rd)
	{
		str = ft_newstr(&rd, fd, str);
		if (ft_strchr(str, '\n'))
		{
			str = ft_next(tmp, str, ft_strchr(str, '\n'), line);
			return (1);
		}
		else
		{
			tmp = ft_next(tmp, str, ft_strchr(str, '\n'), line);
			str = NULL;
		}
		if (!rd && !str && *tmp == '\0')
			return (ft_25strings(tmp));
	}
	*line = tmp;
	return (1);
}
