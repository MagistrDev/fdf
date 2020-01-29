/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:54:26 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 14:31:47 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fig_rotate(t_ptr *ptr, double rot_x, double rot_y, double rot_z)
{
	double x;
	double y;
	double z;

	rot_x = (M_PI / 180 * rot_x);
	y = ptr->y * cos(rot_x) + ptr->z * sin(rot_x);
	z = -(ptr->y * sin(rot_x)) + ptr->z * cos(rot_x);
	ptr->y_o = y;
	ptr->z_o = z;
	rot_y = (M_PI / 180 * rot_y);
	x = ptr->x * cos(rot_y) + ptr->z_o * sin(rot_y);
	z = -(ptr->x * sin(rot_y)) + ptr->z_o * cos(rot_y);
	ptr->x_o = x;
	ptr->z_o = z;
	rot_z = (M_PI / 180 * rot_z) * -1;
	x = ptr->x_o * cos(rot_z) - ptr->y_o * sin(rot_z);
	y = ptr->x_o * sin(rot_z) + ptr->y_o * cos(rot_z);
	ptr->x_o = x;
	ptr->y_o = y;
}

void	rot_ptr(t_ptr *ptr, double x, double y, double z)
{
	t_ptr	*pt;

	pt = ptr;
	while (pt->next)
	{
		fig_rotate(pt, x, y, z);
		pt = pt->next;
	}
}
