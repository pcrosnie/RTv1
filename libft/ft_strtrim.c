/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:55:06 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/03 11:37:27 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s) - 1;
	str = (char *)malloc(n + 1);
	if (!str)
		return (0);
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	str[0] = '\0';
	if (i >= ft_strlen(s) || ft_strlen(s) == 0)
		return (str);
	while (s[n] && (s[n] == '\n' || s[n] == '\t' || s[n] == ' '))
		n--;
	while (i <= n)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
