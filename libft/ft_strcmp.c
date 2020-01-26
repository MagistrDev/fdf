/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:49:22 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/20 22:59:32 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	char *st1;
	char *st2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	st1 = (char*)s1;
	st2 = (char*)s2;
	while (*st1 == *st2 && (*(st1) != 0 || *(st2) != 0))
	{
		st1++;
		st2++;
	}
	return ((unsigned char)*(st1) - (unsigned char)*(st2));
}
