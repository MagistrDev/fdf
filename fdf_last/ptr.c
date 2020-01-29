/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:48:39 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 16:35:11 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptr	*creat_pt(void)
{
	t_ptr	*ptr;

	ptr = (t_ptr*)malloc(sizeof(t_ptr));
	ptr->next = NULL;
	ptr->x = 0;
	ptr->y = 0;
	ptr->z = 0;
	return (ptr);
}

void	free_ptr(t_ptr *ptr)
{
	t_ptr		*pt;
	t_ptr		*mem;

	pt = ptr;
	while (pt)
	{
		mem = pt->next;
		free(pt);
		pt = NULL;
		pt = mem;
	}
}

void	fil_ptr(t_ptr *ptr, char *str, int line)
{
	char	**split_ln;
	t_ptr	*pt;
	int		x;

	x = 0;
	pt = (ptr) ? ptr : creat_pt();
	while (pt->next)
		pt = pt->next;
	split_ln = ft_strsplit(str, ' ');
	while (*(split_ln + x))
	{
		pt->x = x;
		pt->y = line;
		pt->z = ft_atoi(split_ln[x]);
		pt->next = creat_pt();
		pt = pt->next;
		x++;
	}
	ft_arrdel(&split_ln, x);
}
