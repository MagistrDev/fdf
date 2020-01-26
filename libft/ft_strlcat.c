/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:46:26 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/19 23:22:50 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sum;
	size_t	l1;
	char	*s1;
	char	*s2;
	int		i;

	if (*dst == 0 && *src == 0)
		return (0);
	i = 0;
	sum = 0;
	s1 = dst;
	s2 = (char*)src;
	while (*(s1++) && sum < size)
		sum++;
	l1 = sum;
	while (*(s2++))
		sum++;
	s1--;
	s2 = (char*)src;
	(l1 < (size - 1) && *(s2) && size) ? i = 1 : (void)i;
	while (l1++ < (size - 1) && *(s2++) && size)
		*(s1++) = *(s2 - 1);
	(i) ? *s1 = 0 : (void)i;
	return (sum);
}
