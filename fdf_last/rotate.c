/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:05:21 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 17:07:16 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cmp_1(t_ptr **pt, t_window *win)
{
	int out;

	out = 0;
	if (((round(pt[0]->y_o * win->zoom) + win->y_c) > 0)
		&& ((round(pt[0]->y_o * win->zoom) + win->y_c) < win->img.height) &&
		((round(pt[0]->x_o * win->zoom) + win->x_c) < win->img.width) &&
		((round(pt[0]->x_o * win->zoom) + win->x_c) > 0))
		out = 1;
	return (out);
}

void	fil_px(t_window *win, t_ptr **pt)
{
	int		pixel;

	pixel = (int)(win->img.width * (round(pt[0]->y_o * win->zoom) +
		win->y_c) + round(pt[0]->x_o * win->zoom) + win->x_c);
	win->img.img[pixel] = (pt[0]->z) ? 0xff0000 : 0xff00;
}

void	put_img(t_window *win, t_ptr *ptr)
{
	t_ptr	*pt[2];

	pt[0] = ptr;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	rot_ptr(win->ptr, win->r_x, win->r_y, win->r_z);
	ft_bzero((char*)win->img.img, win->img.height * win->img.width * 4);
	while (pt[0])
	{
		pt[1] = pt[0]->next;
		if (pt[1] && (pt[1]->x - 1 == pt[0]->x))
			ft_putline(pt[0], pt[1], 0xffffff, win);
		while (pt[1])
		{
			if ((pt[1]->y == (pt[0]->y + 1)) && (pt[1]->x == pt[0]->x))
				ft_putline(pt[0], pt[1], 0xffffff, win);
			pt[1] = pt[1]->next;
		}
		if (cmp_1(pt, win))
			fil_px(win, pt);
		pt[0] = pt[0]->next;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr,
		win->img.pos_x, win->img.pos_y);
}

void	vertat_os(t_window *win, int key)
{
	if (key == 91)
		win->r_x -= 5;
	if (key == 84)
		win->r_x += 5;
	if (key == 86)
		win->r_y -= 5;
	if (key == 88)
		win->r_y += 5;
	if (key == 89)
		win->r_z += 5;
	if (key == 92)
		win->r_z -= 5;
}

int		key_press(int key, t_window *win)
{
	if (key == ESC)
		exit(0);
	if (key == PLUS)
		win->zoom++;
	if (key == MINUS)
		win->zoom--;
	if (key == 83)
	{
		win->r_x = -30;
		win->r_y = 30;
		win->r_z = 30;
	}
	if (key == 82)
	{
		win->r_x = 0;
		win->r_y = 0;
		win->r_z = 0;
	}
	vertat_os(win, key);
	put_img(win, win->ptr);
	return (0);
}
