/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:37:04 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/23 21:37:37 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*mem;
	char	*v;

	if (!(mem = (char*)malloc(size)))
		return (NULL);
	else
	{
		v = mem;
		while (size--)
			*(mem++) = 0;
	}
	return ((void*)v);
}
