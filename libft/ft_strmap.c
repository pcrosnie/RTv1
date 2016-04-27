/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:20:40 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/04 14:50:55 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (s)
	{
		str = (char *)malloc(ft_strlen(s));
		while (s[i] && str)
		{
			str[i] = (char)(*f)(s[i]);
			i++;
		}
	}
	return (str);
}
