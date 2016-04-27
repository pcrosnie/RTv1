/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:38:17 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/04 14:49:24 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) - 1;
	str = (char *)malloc(sizeof(char) * j);
	while (i < ft_strlen(s) && str)
		str[i++] = s[j--];
	str[i] = '\0';
	return (str);
}
