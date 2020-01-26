/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:51:23 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/28 05:48:20 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntword(char *s, char c)
{
	size_t		i;
	char		*sub;

	i = 0;
	while (*s)
	{
		ft_strskip(&s, c, 0);
		sub = s;
		ft_strskip(&s, c, 1);
		if (s != sub)
			i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ar;
	char		**ok;
	char		*s1;
	char		*s2;

	if (s == NULL)
		return (NULL);
	s1 = (char*)s;
	if (!(ar = (char**)malloc(sizeof(char*) * (ft_cntword(s1, c) + 1))))
		return (NULL);
	ok = ar;
	*(ok + ft_cntword(s1, c)) = NULL;
	while (*s1)
	{
		ft_strskip(&s1, c, 0);
		s2 = s1;
		ft_strskip(&s1, c, 1);
		if (*s2)
			if (!(*ar = ft_strsub(s2, 0, s1 - s2)))
				ft_arrdel(&ok, s1 - s2);
		ar++;
	}
	return (ok);
}
