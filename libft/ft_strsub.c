/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:02:33 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/24 21:02:38 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;
	char	*s3;

	if ((len + 1) == 0 || s == NULL)
		return (NULL);
	if (!(s1 = (char*)malloc(len + 1)))
		return (NULL);
	s3 = s1;
	s2 = (char*)s + start;
	while (len--)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	return (s3);
}
