/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:48:59 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/15 16:05:52 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cut;

	i = (size_t)start;
	j = 0;
	cut = (char *)malloc(len);
	if (cut == NULL || !s)
		return (NULL);
	while (j < len)
	{
		cut[j] = s[i];
		i++;
		j++;
	}
	return (cut);
}
