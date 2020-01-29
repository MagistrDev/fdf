/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 23:41:01 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/24 00:17:20 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*str1;
	char	*str2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	str1 = (char*)s1;
	str2 = (char*)s2;
	while (*str1 == *str2 && (*str1 || *str2) && n > 1)
	{
		n--;
		str1++;
		str2++;
	}
	return ((*str1 == *str2 && (*str1 == 0 || n == 1)) ? 1 : 0);
}
