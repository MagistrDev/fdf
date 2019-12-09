/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 05:51:43 by ecelsa            #+#    #+#             */
/*   Updated: 2019/12/09 00:59:07 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define ESC 65307
#define SPACE 32
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define ENTER 65293
#define TAB 65289

#define ABS(v) ((v) >= 0) ? v : -(v)

int g_rx = 5;
int g_ry = 0;
int g_rz = 0;

typedef struct s_ptr
{
	double x;
	double y;
	double z;

} t_ptr;

t_ptr g_fig[100];
typedef struct	s_mevnt
{
	int		prev_X;
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
	t_mevnt	mouse;
} t_window;

void print_os(t_window *window);
void set_teble(t_window *win);

void ft_putchar(char c)
{
	write(1, &c, 1);
}


void fig_rotate(t_ptr *ptr, double rot_x, double rot_y, double rot_z)
{
	double x = 0;
	double y = 0;
	double z = 0;
	printf("\nrot_x x %f y %f z %f", ptr->x, ptr->y, ptr->z);
	/*rot x*/
	rot_x = (M_PI / 180 * rot_x);
	y = ptr->y * cos(rot_x) + ptr->z * sin(rot_x);
	z = -(ptr->y * sin(rot_x)) + ptr->z * cos(rot_x);
	//ptr->x = x;
	ptr->y = y;
	ptr->z = z;
	printf(" -> x %f y %f z %f\n", ptr->x, ptr->y, ptr->z);
	/*rot y*/
	printf("rot_y x %f y %f z %f", ptr->x, ptr->y, ptr->z);
	rot_y = (M_PI / 180 * rot_y);
	x = ptr->x * cos(rot_y) + ptr->z * sin(rot_y);
	z = -(ptr->x * sin(rot_y)) + ptr->z * cos(rot_y);
	ptr->x = x;
	//ptr->y = y;
	ptr->z = z;
	printf(" -> x %f y %f z %f\n", ptr->x, ptr->y, ptr->z);
	/*rot z*/
	printf("rot_z x %f y %f z %f", ptr->x, ptr->y, ptr->z);
	rot_z = (M_PI / 180 * rot_z);
	x = ptr->x * cos(rot_z) - ptr->y * sin(rot_z);
	y = ptr->x * sin(rot_z) + ptr->y * cos(rot_z);
	ptr->x = x;
	ptr->y = y;
	//ptr->z = z;
	printf(" -> x %f y %f z %f\n", ptr->x, ptr->y, ptr->z);
}

int key_press(int key, t_window *param)
{
	t_window win;

	win = *param;
	ft_putchar(key);
	mlx_pixel_put(win.mlx_ptr, win.win_ptr, key, key, 0xffffff);
	printf("%d ", key);
	if (key == RIGHT)
	{
		if (win.img_pos_x < (win.size_x - win.img_width))
			param->img_pos_x++;
	}
	if (key == LEFT)
	{
		if (param->img_pos_x > 0)
			param->img_pos_x--;
	}
	if (key == DOWN)
	{
		if (win.img_pos_y < (win.size_y - win.img_width))
			param->img_pos_y++;
	}
	if (key == UP)
	{
		if (param->img_pos_y > 0)
			param->img_pos_y--;
	}
	if (key == SPACE)
	{
		//fig_rotate(&g_fig[0],0,0,90);
		fig_rotate(&g_fig[0], g_rx, g_ry, g_rz);
		fig_rotate(&g_fig[1], g_rx, g_ry, g_rz);
		fig_rotate(&g_fig[2], g_rx, g_ry, g_rz);
		fig_rotate(&g_fig[3], g_rx, g_ry, g_rz);
		set_teble(param);
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		print_os(param);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.imp_ptr, win.img_pos_x, win.img_pos_y);
	}
	if (key == UP | key == DOWN | key == LEFT || key == RIGHT)
	{
		/*printf("\n x - %d y- %d\n",win.img_pos_x,win.img_pos_y);*/
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		print_os(param);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.imp_ptr, win.img_pos_x, win.img_pos_y);
	}
	if (key == ESC)
	{
		printf("\n");
		exit(0);
	}
	return (0);
}

void print_os(t_window *window)
{
	for (int i = 0; i < window->size_x; i++)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, i, window->size_y / 2, 0xffffff);
	}
	for (int i = 0; i < window->size_y; i++)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->size_x / 2, i, 0xffffff);
	}
}

void set_teble(t_window *win)
{
	int *i;

	i = win->img;
	int y_c = win->img_height / 2;
	int x_c = win->img_width / 2;
	win->img[(int)(win->img_width * (round(g_fig[0].y) + y_c) + round(g_fig[0].x) + x_c)] = 0xff;
	win->img[(int)(win->img_width * (round(g_fig[1].y) + y_c) + round(g_fig[1].x) + x_c)] = 0xff;
	win->img[(int)(win->img_width * (round(g_fig[2].y) + y_c) + round(g_fig[2].x) + x_c)] = 0xff;
	win->img[(int)(win->img_width * (round(g_fig[3].y) + y_c) + round(g_fig[3].x) + x_c)] = 0xff;
}
int mouse_move(int x, int y, void *param)
{
	(void)param;
	write(1, "!",1);
	printf("x-%i y-%i\n",x, y);
	return (0);
}
int mouse_press(int button, int x, int y, void *param)
{
	t_window *win;

	win = (t_window*)param;
	win->mouse->x = x;
	
	write(1, "!",1);
	printf("btn-%i x-%i y-%i\n",button, x, y);
	return (0);
}
int mouse_release(int button, int x, int y, void *param)
{
	(void)param;
	printf("--btn-%i x-%i y-%i\n",button, x, y);
	return (0);
}
int mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	write(1, "!",1);
	printf(" hook btn-%i x-%i y-%i\n",button, x, y);
	return (0);
}

void setup_controls(void *param)
{
	t_window *win;
	win = (t_window*)param;
	mlx_hook(win->win_ptr, 2, 1, key_press, param);
	//mlx_hook(win->win_ptr, 17, 0, close, fdf);
	mlx_hook(win->win_ptr, 4, (1L<<2), mouse_press, win);
	mlx_hook(win->win_ptr, 5, (1L<<3), mouse_release, win);
    mlx_hook(win->win_ptr, 6, (1L<<13), mouse_move, win);
	//mlx_hook(win->win_ptr, 6, 0, mouse_bla, win);
	
}
	

int main(int argc, char **argv)
{
	t_window window;

	window.size_x = 600;
	window.size_y = 600;

	window.img_width = 100;
	window.img_height = 100;
	window.img_pos_x = -50;
	window.img_pos_y = -50;
	//char	*title = "ffff";

	g_fig[0].x = -20;
	g_fig[0].y = 20;
	g_fig[0].z = 0;
	g_fig[1].x = 20;
	g_fig[1].y = 20;
	g_fig[1].z = 0;

	g_fig[2].x = 20;
	g_fig[2].y = -20;
	g_fig[2].z = 0;
	g_fig[3].x = -20;
	g_fig[3].y = -20;
	g_fig[4].z = 0;
	window.img_pos_x = 250;
	window.img_pos_y = 250;
	(void)argc;
	printf("%f\n", M_PI);
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.size_x, window.size_y, *argv);
	/*mlx_pixel_put(window.mlx_ptr, window.win_ptr, 250, 250, 0xffffff);*/
	print_os(&window);
	window.imp_ptr = mlx_new_image(window.mlx_ptr, window.img_width, window.img_height);
	window.img = (int *)mlx_get_data_addr(window.imp_ptr, &window.img_bpp, &window.img_size_line, &window.img_endian);
	printf("\n img bits_per_pixel - %d, size_line - %d, endian - %d\n", window.img_bpp, window.img_size_line, window.img_endian);
	/*for (int i = 0; i < window.img_width * window.img_height ;i++)
	{
		window.img[i] = 0xffffffff;
	}*/
	set_teble(&window);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.imp_ptr, window.img_pos_x, window.img_pos_y);
	//mlx_key_hook(window.win_ptr, deal_key, &window);
	//mlx_hook(window.win_ptr, 6, 0, mouse_bla, &window);
	//mlx_mouse_hook(window.win_ptr, mouse_hook, &window);
	setup_controls(&window);
	//mlx_hook(window.win_ptr, 2, (1L<<0), deal_key, &window);
	mlx_loop(window.mlx_ptr);
	write(1, "\nfdfdfdf\n", 9);
	return (0);
}
