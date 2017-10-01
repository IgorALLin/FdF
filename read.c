/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:55:14 by ichebota          #+#    #+#             */
/*   Updated: 2017/09/12 18:59:53 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixels	*ft_new_pixel(char *pic, int x, int y)
{
	t_pixels	*new;
	t_pixel		*pixel;

	new = (t_pixels*)malloc(sizeof(t_pixels));
	pixel = (t_pixel*)malloc(sizeof(t_pixel));
	pixel->x = x;
	pixel->y = y;
	pixel->z = ft_atoi(pic);
	pixel->color = ft_add_color(pic, pixel->z);
	new->curr = pixel;
	new->left = NULL;
	new->up = NULL;
	new->bufup = NULL;
	new->next = NULL;
	return (new);
}

void		ft_add_connections(t_pixels **head, t_pixels **buf, t_pixels **new)
{
	t_pixels	*n;
	t_pixels	*h;
	t_pixels	*b;

	n = *new;
	h = *head;
	b = *buf;
	if (n->curr->x != 0)
		n->left = b->curr;
	if (n->curr->y != 0 && n->curr->x == h->bufup->curr->x)
	{
		n->up = h->bufup->curr;
		h->bufup = h->bufup->next;
	}
}

void		ft_put_pixel(char *pic, t_pixels **head, int x, int y)
{
	t_pixels	*new;
	t_pixels	*tmp;
	t_pixels	*buf;

	tmp = *head;
	new = ft_new_pixel(pic, x, y);
	if (tmp == NULL)
	{
		tmp = new;
		tmp->last = new;
		tmp->bufup = new;
		*head = tmp;
	}
	else
	{
		buf = tmp->last;
		buf->next = new;
		tmp->last = new;
		ft_add_connections(&tmp, &buf, &new);
		*head = tmp;
	}
}

void		ft_add_pixels(t_data *data, char *line, int y, t_pixels **pixels)
{
	char		**split;
	int			x;

	x = 0;
	split = ft_strsplit(line, ' ');
	while (split[x])
	{
		ft_put_pixel(split[x], pixels, x, y);
		x++;
	}
	ft_freestr(split);
	data->len[y] = x;
}

void		ft_read(t_data *data, int fd)
{
	char		*line;
	int			y;
	t_pixels	*pixels;

	y = 0;
	pixels = NULL;
	data->len = ft_creatint(data->ysize, 0);
	while (get_next_line(fd, &line) != 0)
	{
		ft_check_line(line);
		ft_add_pixels(data, line, y, &pixels);
		y++;
		free(line);
	}
	data->pixels = pixels;
}
