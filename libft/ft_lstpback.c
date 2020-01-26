/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 01:25:33 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/28 02:24:58 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpback(t_list **begin_list, void *content)
{
	t_list	*cursor;

	cursor = ft_lstnew(content, ft_strlen((char*)content));
	if (!(*begin_list))
		*begin_list = cursor;
	else
	{
		cursor->next = *begin_list;
		*begin_list = cursor;
	}
}
