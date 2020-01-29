/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:09:00 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 23:18:48 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = dest;
	s2 = (char*)src;
	while (*s1)
		s1++;
	while (*s2 && i++ < n)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	return (dest);
}
