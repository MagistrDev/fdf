/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 23:01:19 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/20 23:23:11 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *st1;
	char *st2;

	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	st1 = (char*)s1;
	st2 = (char*)s2;
	while (*st1 == *st2 && --n && (*(st1) != 0 || *(st2) != 0))
	{
		st1++;
		st2++;
	}
	return ((unsigned char)*(st1) - (unsigned char)*(st2));
}
