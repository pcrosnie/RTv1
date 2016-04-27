/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:41:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/03 14:42:26 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lsnew;

	lsnew = (t_list *)malloc(sizeof(t_list));
	if (lsnew == NULL)
		return (NULL);
	lsnew->next = NULL;
	if (content == NULL)
	{
		lsnew->content = NULL;
		lsnew->content_size = 0;
		return (lsnew);
	}
	lsnew->content = (t_list*)ft_memalloc(content_size);
	ft_memcpy(lsnew->content, content, content_size);
	lsnew->content_size = content_size;
	return (lsnew);
}
