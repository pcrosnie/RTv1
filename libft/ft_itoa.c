/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:39:09 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/13 19:27:17 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_for_ten_m(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	int				j;
	unsigned int	nb;
	char			*str;

	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	j = 1;
	nb = n;
	i = ft_count_for_ten_m(n);
	str = (char *)ft_memalloc(i + 3);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
		j = 0;
	}
	while (i > 0)
	{
		str[i-- - j] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
