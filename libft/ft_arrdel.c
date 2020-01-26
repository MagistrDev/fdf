/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:04:59 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/22 22:44:09 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_arrdel(char ***arr, size_t size)
{
	char	**mas;

	if (arr == NULL)
		return ;
	mas = *arr;
	while (size)
	{
		free(*mas);
		mas++;
		size--;
	}
	free(*arr);
	*arr = NULL;
}
