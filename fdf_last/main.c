/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:18:02 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 12:49:04 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putline(t_ptr *pt1, t_ptr *pt2, int col, t_window *win)
{
	t_put_line	pl;

	pl.y_c = win->img.height / 2;
	pl.x_c = win->img.width / 2;
	pl.xst = pt1->x_o * win->zoom;
	pl.yst = pt1->y_o * win->zoom;
	pl.xend = pt2->x_o * win->zoom;
	pl.yend = pt2->y_o * win->zoom;
	pl.a = fabs(pl.xend - pl.xst);
	pl.b = fabs(pl.yend - pl.yst);
	pl.l = round((pl.a > pl.b) ? pl.a : pl.b);
	pl.dx = (pt2->x_o * win->zoom - pt1->x_o * win->zoom) / pl.l;
	pl.dy = (pt2->y_o * win->zoom - pt1->y_o * win->zoom) / pl.l;
	pl.i = 1;
	while (pl.i < pl.l)
	{
		pl.xst = pl.xst + pl.dx;
		pl.yst = pl.yst + pl.dy;
		if (((pl.xst + pl.x_c) > 0) && ((pl.xst + pl.x_c) < win->img.width) &&
			((pl.yst + pl.y_c) < win->img.height) && ((pl.yst + pl.y_c) > 0))
			win->img.img[(int)(win->img.width * (round(pl.yst) + pl.y_c)
				+ round(pl.xst) + pl.x_c)] = col;
		pl.i++;
	}
}

void	put_img(t_window *win, t_ptr *ptr)
{
	t_ptr	*pt;
	t_ptr	*pt2;
	int		pixel;

	pt = ptr;
	while (pt)
	{
		pt2 = pt->next;
		if (pt2 && (pt2->x - 1 == pt->x))
			ft_putline(pt, pt2, 0xf0000f, win);
		while (pt2)
		{
			if ((pt2->y == (pt->y + 1)) && (pt2->x == pt->x))
				ft_putline(pt, pt2, 0xf0000f, win);
			pt2 = pt2->next;
		}
		if (((round(pt->y_o * win->zoom) + win->y_c) > 0)
			&& ((round(pt->y_o * win->zoom) + win->y_c) < win->img.height) &&
			((round(pt->x_o * win->zoom) + win->x_c) < win->img.width) &&
			((round(pt->x_o * win->zoom) + win->x_c) > 0))
		{
			pixel = (int)(win->img.width * (round(pt->y_o * win->zoom) +
				win->y_c) + round(pt->x_o * win->zoom) + win->x_c);
			win->img.img[pixel] = (pt->z) ? 0xff0000 : 0xff00;
		}
		pt = pt->next;
	}
}

int		key_press(int key, t_window *win)
{
	ft_putnbr(key);
	ft_putstr(" ");
	if (key == ESC)
		exit(0);
	if (key == PLUS)
	{
		win->zoom++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		rot_ptr(win->ptr, 0, 0, 0);
		ft_bzero((char*)win->img.img, win->img.height * win->img.width * 4);
		put_img(win, win->ptr);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr,
			win->img.pos_x, win->img.pos_y);
	}
	if (key == MINUS)
	{
		win->zoom--;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		rot_ptr(win->ptr, 0, 0, 0);
		ft_bzero((char*)win->img.img, win->img.height * win->img.width * 4);
		put_img(win, win->ptr);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr,
			win->img.pos_x, win->img.pos_y);
	}
	if (key == 83)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		rot_ptr(win->ptr, 30, 30, 30);
		ft_bzero((char*)win->img.img, win->img.height * win->img.width * 4);
		put_img(win, win->ptr);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr,
			win->img.pos_x, win->img.pos_y);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			fr;
	char		*buf;
	// int			pixel;
	// t_ptr		*pt[2];
	// t_window	win;
	fr = 1;

	fr &= 3;
	// win.ln = 0;
	// win.ptr = creat_pt();
	fr = 1;
	buf = (char*)malloc(1000);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			// while (get_next_line(fd, &buf))
			while (fr)
			{
			fr = read(fd, buf, 500);
			// 	fil_ptr(win.ptr, buf, win.ln);
				// win.ln++;
			}
			close(fd);
		}
	}
			free(buf);
	// win.size_x = 800;
	// win.size_y = 800;
	// win.zoom = 1;
	// win.img.width = 800;
	// win.img.height = 800;
	// win.img.pos_x = 0;
	// win.img.pos_y = 0;
	// win.y_c = win.img.height / 2;
	// win.x_c = win.img.width / 2;
	// win.mlx_ptr = mlx_init();
	// win.win_ptr = mlx_new_window(win.mlx_ptr, win.size_x,
	// 	win.size_y, *argv);
	// win.img.img_ptr = mlx_new_image(win.mlx_ptr, win.img.width,
	// 	win.img.height);
	// win.img.img = (int *)mlx_get_data_addr(win.img.img_ptr,
	// 	&win.img.bpp, &win.img.size_line, &win.img.endian);
	// rot_ptr(win.ptr, 30, 30, 30);
	// (void)pt;
	// (void)pixel;
	// //ft_bzero((char*)win.img.img, win.img.height * win.img.width * 4);
	// pt[0] = win.ptr;
	// while (pt[0])
	// {
	// 	if (((round(pt[0]->y_o * win.zoom) + win.y_c) < win.img.height) &&
	// 		((round(pt[0]->x_o * win.zoom) + win.x_c) < win.img.width))
	// 	{
	// 		pixel = (int)(win.img.width * (round(pt[0]->y_o * win.zoom) +
	// 			win.y_c) + round(pt[0]->x_o * win.zoom) + win.x_c);
	// 		win.img.img[pixel] = (pt[0]->z) ? 0xff0000 : 0xff00;
	// 	}
	// 	pt[1] = pt[0]->next;
	// 	if (pt[1] && (pt[1]->x - 1 == pt[0]->x))
	// 		ft_putline(pt[0], pt[1], 0xf0000f, &win);
	// 	while (pt[1])
	// 	{
	// 		if ((pt[1]->y == (pt[0]->y + 1)) && (pt[1]->x == pt[0]->x))
	// 			ft_putline(pt[0], pt[1], 0xf0000f, &win);
	// 		pt[1] = pt[1]->next;
	// 	}
	// 	pt[0] = pt[0]->next;
	// }
	// mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img.img_ptr,
	// 	win.img.pos_x, win.img.pos_y);
	// mlx_hook(win.win_ptr, 2, 1, key_press, &win);
	// mlx_loop(win.mlx_ptr);
	return (0);
}

