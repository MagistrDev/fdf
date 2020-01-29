/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:23:42 by ecelsa            #+#    #+#             */
/*   Updated: 2019/11/17 06:58:19 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (*str)
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	if (c == 0)
		return ((char*)str);
	return (NULL);
}
