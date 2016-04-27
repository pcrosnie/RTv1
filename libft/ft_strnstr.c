/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/17 11:55:55 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] && i < n)
		{
			j++;
			if (j == ft_strlen(s2))
			{
				return ((char *)s1 + i - j + 1);
			}
			i++;
		}
		i = i - j + 1;
	}
	return (NULL);
}
