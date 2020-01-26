/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:38:25 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/23 21:47:43 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*s;

	if (size + 1 < size)
		return (NULL);
	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	else
	{
		s = str;
		while (size-- + 1)
			*(s++) = 0;
	}
	return (str);
}
