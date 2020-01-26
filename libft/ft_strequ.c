/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:54:58 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/23 23:07:20 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	str1 = (char*)s1;
	str2 = (char*)s2;
	while (*str1 == *str2 && (*str1 || *str2))
	{
		str1++;
		str2++;
	}
	return ((*str1 == *str2 && *str1 == 0) ? 1 : 0);
}
