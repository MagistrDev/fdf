/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:36:46 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 22:35:10 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*s1;
	char	*s2;

	if (dest == NULL && src == NULL)
		return (NULL);
	s1 = dest;
	s2 = (char*)src;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	return (dest);
}
