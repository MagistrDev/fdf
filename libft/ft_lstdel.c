/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 01:27:18 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/27 01:44:00 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (alst != NULL)
	{
		while ((*alst)->next)
		{
			buf = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = buf;
		}
		ft_lstdelone(alst, del);
		*alst = NULL;
	}
}
