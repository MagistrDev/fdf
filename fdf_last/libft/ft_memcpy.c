/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:45:35 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 21:36:17 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem;
	unsigned char	*str;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	mem = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (i++ < n)
		*(mem + i - 1) = *(str + i - 1);
	return (dest);
}
