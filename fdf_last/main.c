/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:18:02 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 19:36:27 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help_smile(t_put_line *pl)
{
	pl->a = fabs(pl->xend - pl->xst);
	pl->b = fabs(pl->yend - pl->yst);
	pl->l = round((pl->a > pl->b) ? pl->a : pl->b);
}

void	ft_putline(t_ptr *pt1, t_ptr *pt2, int col, t_window *win)
{
	t_put_line	pl;

	pl.y_c = win->img.height / 2;
	pl.x_c = win->img.width / 2;
	pl.xst = pt1->x_o * win->zoom;
	pl.yst = pt1->y_o * win->zoom;
	pl.xend = pt2->x_o * win->zoom;
	pl.yend = pt2->y_o * win->zoom;
	help_smile(&pl);
	pl.dx = (pt2->x_o * win->zoom - pt1->x_o * win->zoom) / pl.l;
	pl.dy = (pt2->y_o * win->zoom - pt1->y_o * win->zoom) / pl.l;
	pl.i = 1;
	while (pl.i < pl.l)
	{
		pl.c = ((pt1->z) || (pt2->z)) ? col : 0xff00;
		pl.xst = pl.xst + pl.dx;
		pl.yst = pl.yst + pl.dy;
		if (((pl.xst + pl.x_c) > 0) && ((pl.xst + pl.x_c) < win->img.width - 2)
		&& ((pl.yst + pl.y_c) < win->img.height - 2) && ((pl.yst + pl.y_c) > 0))
			win->img.img[(int)(win->img.width * (round(pl.yst) + pl.y_c) +
			round(pl.xst) + pl.x_c)] = pl.c;
		pl.i++;
	}
}

void	fil_window(t_window *win)
{
	win->size_x = 800;
	win->size_y = 800;
	win->zoom = 5;
	win->z = 1;
	win->img.width = 800;
	win->img.height = 800;
	win->img.pos_x = 0;
	win->img.pos_y = 0;
	win->y_c = win->img.height / 2;
	win->x_c = win->img.width / 2;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->size_x, win->size_y,
		win->argv[1]);
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, win->img.width,
		win->img.height);
	win->img.img = (int *)mlx_get_data_addr(win->img.img_ptr, &win->img.bpp,
		&win->img.size_line, &win->img.endian);
	ft_bzero((char*)win->img.img, win->img.height * win->img.width * 4);
	win->r_x = 0;
	win->r_y = 0;
	win->r_x = 0;
}

void	input_arg(int argc, char **argv, t_window *win)
{
	int		fd;
	char	*buf;

	fd = 0;
	win->ln = 0;
	win->ptr = creat_pt();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((fd > 0) && (read(fd, win->help, 3) > 0))
		{
			close(fd);
			fd = open(argv[1], O_RDONLY);
			while (get_next_line(fd, &buf))
			{
				fil_ptr(win->ptr, buf, win->ln, win);
				ft_strdel(&buf);
				win->ln++;
			}
			ft_strdel(&buf);
			close(fd);
		}
		else
			exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_window	win;

	win.argv = argv;
	input_arg(argc, argv, &win);
	fil_window(&win);
	put_img(&win, win.ptr);
	mlx_hook(win.win_ptr, 2, 1, key_press, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
