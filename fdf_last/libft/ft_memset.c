/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:21:01 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/15 22:39:45 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	ch;

	ch = (unsigned char)c;
	mem = (unsigned char *)s;
	while (n--)
		*(mem + n) = ch;
	return (s);
}
