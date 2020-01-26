/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:46:31 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 22:46:35 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem;
	unsigned char	*str;

	if (dest == NULL && src == NULL)
		return (NULL);
	mem = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (n--)
	{
		*(mem + n) = *(str + n);
	}
	return (dest);
}
