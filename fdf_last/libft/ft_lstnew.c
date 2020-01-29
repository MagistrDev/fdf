/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:12:12 by ecelsa            #+#    #+#             */
/*   Updated: 2019/09/28 05:12:14 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list*)malloc(sizeof(t_list) * 1);
	if (fresh == NULL)
		return (NULL);
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		fresh->next = NULL;
		return (fresh);
	}
	fresh->content = (void*)malloc(content_size);
	if (fresh->content == NULL)
	{
		free(fresh);
		return (NULL);
	}
	ft_memcpy(fresh->content, content, content_size);
	fresh->content_size = content_size;
	fresh->next = NULL;
	return (fresh);
}
