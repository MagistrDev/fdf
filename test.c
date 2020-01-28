/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:18:02 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/28 13:53:49 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#define ESC 53
#define SPACE 49

typedef struct	s_ptr
{
	double			x;
	double			y;
	double			z;
	double			x_o;
	double			y_o;
	double			z_o;
	struct	s_ptr	*next;
} 				t_ptr;

typedef struct	s_mevnt
{
	int		prev_x;
	int		prev_y;
	int		x;
	int		y;
	int		btn;
	
}				t_mevnt;

typedef struct	s_window
{
	void *mlx_ptr;
	void *win_ptr;
	void *imp_ptr;
	int *img;
	int size_x;
	int size_y;
	int img_bpp;
	int img_size_line;
	int img_endian;
	int img_width;
	int img_height;
	int img_pos_x;
	int img_pos_y;
	int y_c;
	int x_c;
	t_mevnt	mouse;
} 				t_window;

t_ptr	*creat_pt()
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
	while (pt->next)
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
}

void fig_rotate(t_ptr *ptr, double rot_x, double rot_y, double rot_z)
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
	rot_z = (M_PI / 180 * rot_z);
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

int		key_press(int key, t_window *param)
{
	(void)param;
	ft_putnbr(key);
	ft_putstr(" ");
	if (key == ESC)
		exit(0);
	if (key == SPACE)
	{
		
	}
	return (0);
}

void	put_img(t_window *win, t_ptr *ptr)
{
	t_ptr *pt;

	pt = ptr;

	while (pt)
	{
		
		pt = pt->next;
	}
}

void ft_putline(t_ptr *pt1, t_ptr *pt2, int col, t_window *win)
{
	
	float dx;
	float dy;
	float xst;
	float xend;
	float yst;
	float yend;
	int l;
	int i;
	int y_c = win->img_height / 2;
	int x_c = win->img_width / 2;
	
	xst = pt1->x_o*15;
	yst = pt1->y_o*15;
	xend = pt2->x_o*15;
	yend = pt2->y_o*15;
	printf("%f %f\n",fabs(yend - yst),fabs(xend - xst));
	double a = fabs(xend - xst), b = fabs(yend - yst);
	l = round((a > b) ? a : b);

	dx = (pt2->x_o*15 - pt1->x_o*15) / l;
 	dy = (pt2->y_o*15 - pt1->y_o*15) / l;
 	i = 1;
 	while (i < l)
 	{
		xst = xst + dx;
		yst = yst + dy;
		win->img[(int)(win->img_width * (round(yst) + y_c) + round(xst) + x_c)] = col;
		i++;
 	}	 
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*buf;
	char	**split_ln;
	t_ptr	*ptr;
	int		ln;

	ln = 0;
	ptr = creat_pt();
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			while(get_next_line(fd, &buf))
			{
				printf("%s\n", buf);
				fil_ptr(ptr, buf, ln);
				ln++;
			}
			free(buf);
			close(fd);
		}
	}
	t_window window;

	window.size_x = 800;
	window.size_y = 800;

	window.img_width = 800;
	window.img_height = 800;
	window.img_pos_x = 0;
	window.img_pos_y = 0;
	window.y_c = window.img_height / 2;
	window.x_c = window.img_width / 2;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.size_x, 
		window.size_y, *argv);
	window.imp_ptr = mlx_new_image(window.mlx_ptr, window.img_width, 
		window.img_height);
	window.img = (int *)mlx_get_data_addr(window.imp_ptr, 
		&window.img_bpp, &window.img_size_line, &window.img_endian);
	rot_ptr(ptr, -30, -30, -30);
		int *i;

	i = window.img;
	ft_bzero((char*)window.img, window.img_height * window.img_width * 4);
	t_ptr	*pt;
	t_ptr	*pt2;
	int		pixel;
	pt = ptr;
	
	while (pt)
	{
		pixel = (int)(window.img_width * (round(pt->y_o*15) + window.y_c) + round(pt->x_o*15) + window.x_c);
		window.img[pixel] = (pt->z) ? 0xff0000 : 0xff00;
		pt2 = pt->next;
		if (pt2)
			ft_putline(pt, pt2, 0xf0000f, &window);
		pt = pt->next;
		
	}
	pt = ptr;	
	// while (pt)
	// {
	// 	pt2 = pt->next;
	// 	if (pt2)
	// 		ft_putline(pt, pt2, 0xff, &window);
	// 	pt = pt->next;
		
	// }
	
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.imp_ptr, window.img_pos_x, window.img_pos_y);
	//put_img(&window, ptr);
	mlx_hook(window.win_ptr, 2, 1, key_press, &window);
	// out_img(&window, ptr);
	// set_table(&window);
	// mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.imp_ptr,
		// window.img_pos_x, window.img_pos_y);
	// setup_controls(&window);
	free_ptr(ptr);
	mlx_loop(window.mlx_ptr);
	return (0);
}
