/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 09:01:05 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/26 10:44:30 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*str;
	int		l;
	int		**map;

	l = 0;
	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			exit(-1);
		
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			l++;
			ft_str	split(line, ' ')
			
			ft_strdel(&line);
		}
		ft_strdel(&line);
		printf(" val line %i\n", l);
		close(fd);
	}
	return (0);
}