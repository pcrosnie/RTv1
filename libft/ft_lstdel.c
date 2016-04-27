/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:33:14 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/03 15:36:05 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	if ((*alst))
	{
		ptr = *alst;
		while (ptr != NULL)
		{
			(*alst) = (*alst)->next;
			del(ptr->content, ptr->content_size);
			ptr = *alst;
		}
		ft_memdel((void **)alst);
	}
}
