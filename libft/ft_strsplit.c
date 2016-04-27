/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:22:32 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/02/10 11:22:20 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *s, char c)
{
	int		i;
	int		wrd;

	i = 0;
	wrd = 0;
	if (s[i] != c)
	{
		i++;
		wrd++;
	}
	while (s[i])
	{
		if (s[i] == c)
			if (s[i + 1] != c)
				wrd++;
		i++;
	}
	return (wrd);
}

static char	**ft_subsplit(char const *s, char c, char **dgrid)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			dgrid[k] = ft_strsub(s, j, (i - j));
			k++;
		}
		else
			i++;
	}
	dgrid[k] = NULL;
	return (dgrid);
}

char		**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			k;
	char		**dgrid;

	i = 0;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	dgrid = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c) + 1));
	if (dgrid)
	{
		return (ft_subsplit(s, c, dgrid));
	}
	else
		return (NULL);
}
