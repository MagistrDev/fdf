/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:22:43 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 19:46:16 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char*)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*mem == chr)
			return (mem);
		mem++;
		i++;
	}
	return (NULL);
}
