/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:11:59 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/24 20:21:08 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	char	*str;

	if (s != NULL)
	{
		str = (char*)s;
		while (*str)
		{
			write(fd, str, 1);
			str++;
		}
	}
}