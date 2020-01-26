/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:49:22 by ecelsa            #+#    #+#             */
/*   Updated: 2019/11/17 06:58:22 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	char			*ptr;

	ptr = NULL;
	str = (unsigned char*)s;
	while (*str)
	{
		if (*str == c)
			ptr = (char*)str;
		str++;
	}
	if (c == 0)
		return ((char*)str);
	return (ptr);
}
