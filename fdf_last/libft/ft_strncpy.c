/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:46:04 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 22:46:09 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	s1 = dest;
	s2 = (char*)src;
	while (i < n)
	{
		*s1 = *s2;
		s1++;
		s2 += (!*s2) ? 0 : 1;
		i++;
	}
	return (dest);
}
