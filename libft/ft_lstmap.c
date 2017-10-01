/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichebota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:03:00 by ichebota          #+#    #+#             */
/*   Updated: 2016/12/14 16:05:36 by ichebota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;

	ptr = NULL;
	if (lst)
	{
		ptr = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (lst->next)
			ptr->next = ft_lstmap(lst->next, f);
		return (ptr);
	}
	return (NULL);
}
