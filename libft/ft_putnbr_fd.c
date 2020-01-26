/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:21:36 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/24 20:29:53 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	rev[12];

	(n < 0) ? write(fd, "-", 1) : (void)i;
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
		n *= -1;
	i = 0;
	while (n > 0)
	{
		rev[i++] = (n % 10 + 48);
		n /= 10;
	}
	while (i-- > 0)
		write(fd, &rev[i], 1);
}
