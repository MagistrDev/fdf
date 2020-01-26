/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:52:42 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/23 21:54:50 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char*))
{
	char	*str;

	str = s;
	if (s != NULL && f != NULL)
		while (*str)
		{
			(*f)(&(*str));
			str++;
		}
}
