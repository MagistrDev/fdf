/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:59:28 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/18 19:54:12 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*str;

	size = 0;
	str = (char *)s;
	while (*str++ != 0)
		size++;
	size++;
	str = NULL;
	str = (char*)malloc(size);
	if (str == NULL)
		return (NULL);
	while (size--)
		str[size] = s[size];
	return (str);
}
