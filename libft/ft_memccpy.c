/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:41:03 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 21:22:40 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destn;
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	i = 0;
	destn = (unsigned char*)dest;
	str = (unsigned char*)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		*destn = *str;
		destn++;
		str++;
		if (*(str - 1) == ch)
			return (destn);
		i++;
	}
	return (NULL);
}
