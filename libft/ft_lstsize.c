/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 02:23:46 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/27 02:28:41 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(t_list *begin_list)
{
	size_t	x;
	t_list	*tmp;

	x = 0;
	tmp = begin_list;
	if (begin_list == NULL)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		x++;
	}
	return (x);
}
