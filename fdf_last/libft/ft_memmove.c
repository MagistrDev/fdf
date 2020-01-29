/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:05:43 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 21:50:18 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*mem;
	unsigned char	*str;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	mem = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (str == mem)
		return (dest);
	else if (str < mem)
		while (n--)
			*(mem + n) = *(str + n);
	else
		while (i++ < n)
			*(mem + i - 1) = *(str + i - 1);
	return (dest);
}
