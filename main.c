/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 05:51:43 by ecelsa            #+#    #+#             */
/*   Updated: 2019/12/11 00:38:26 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int g_rx = 1;
int g_ry = 1;
int g_rz = 3;
int elem = 9;
t_ptr g_fig[100];

void print_os(t_window *window);
void set_teble(t_window *win);

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;

	mem = (unsigned char *)s;
	while (n--)
		*(mem + n) = 0;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putline(t_ptr pt1, t_ptr pt2, int col, t_window *win)
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
	
	xst = pt1.x;
	yst = pt1.y;
	xend = pt2.x;
	yend = pt2.y;
	printf("%f %f\n",ABS(yend - yst),ABS(xend - xst));
	l = round((fabs(xend - xst) > fabs(yend - yst)) ? fabs(xend - xst) : fabs(yend - yst));

	dx = (pt2.x - pt1.x) / l;
 	dy = (pt2.y - pt1.y) / l;
 	i = 1;
 	while (i < l)
 	{
		xst = xst + dx;
		yst = yst + dy;
		win->img[(int)(win->img_width * (round(yst) + y_c) + round(xst) + x_c)] = col;
		i++;
 	}	 
}

void fig_rotate(t_ptr *ptr, double rot_x, double rot_y, double rot_z)
{
	double x = 0;
	double y = 0;
	double z = 0;
	//printf("\nrot_x x %f y %f z %f", ptr->x, ptr->y, ptr->z);
	/*rot x*/
	rot_x = (M_PI / 180 * rot_x);
	y = ptr->y * cos(rot_x) + ptr->z * sin(rot_x);
	z = -(ptr->y * sin(rot_x)) + ptr->z * cos(rot_x);
	//ptr->x = x;
	ptr->y = y;
	ptr->z = z;
	//printf(" -> x %f y %f z %f\n", ptr->x, ptr->y, ptr->z);
	/*rot y*/
	//printf("rot_y x %f y %f z %f", ptr->x, ptr->y, ptr->z);
	rot_y = (M_PI / 180 * rot_y);
	x = ptr->x * cos(rot_y) + ptr->z * sin(rot_y);
	z = -(ptr->x * sin(rot_y)) + ptr->z * cos(rot_y);
	ptr->x = x;
	//ptr->y = y;
	ptr->z = z;
	//printf(" -> x %f y %f z %f\n", ptr->x, ptr->y, ptr->z);
	/*rot z*/
	//printf("rot_z x %f y %f z %f", ptr->x, ptr->y, ptr->z);
	rot_z = (M_PI / 180 * rot_z);
	x = ptr->x * cos(rot_z) - ptr->y * sin(rot_z);
	y = ptr->x * sin(rot_z) + ptr->y * cos(rot_z);
	ptr->x = x;
	ptr->y = y;
	//ptr->z = z;
	//printf(" -> x %f y %f z %f\n", ptr->x, ptr->y, ptr->z);
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
	ft_bzero((char*)win->img, win->img_height * win->img_width * 4);
	for (int x = 0; x < elem;x++)
		win->img[(int)(win->img_width * (round(g_fig[x].y) + y_c) + round(g_fig[x].x) + x_c)] = 0xff;

	ft_putline(g_fig[0],g_fig[1],0xff00,win);
	ft_putline(g_fig[1],g_fig[2],0xff00,win);
	ft_putline(g_fig[2],g_fig[3],0xff00,win);
	ft_putline(g_fig[3],g_fig[0],0xff00,win);
	ft_putline(g_fig[4],g_fig[5],0xff00,win);
	ft_putline(g_fig[5],g_fig[6],0xff00,win);
	ft_putline(g_fig[6],g_fig[7],0xff00,win);
	ft_putline(g_fig[7],g_fig[4],0xff00,win);
	ft_putline(g_fig[0],g_fig[4],0xff00,win);
	ft_putline(g_fig[1],g_fig[5],0xff00,win);
	ft_putline(g_fig[2],g_fig[6],0xff00,win);
	ft_putline(g_fig[3],g_fig[7],0xff00,win);
}
void input_pt(t_ptr *pt, double x, double y, double z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
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

	input_pt(&g_fig[0],-20, 20, -20);
	input_pt(&g_fig[1],20, 20, -20);
	input_pt(&g_fig[2],20, -20, -20);
	input_pt(&g_fig[3],-20, -20, -20);
	input_pt(&g_fig[4],-20, 20, 20);
	input_pt(&g_fig[5], 20, 20, 20);
	input_pt(&g_fig[6], 20, -20, 20);
	input_pt(&g_fig[7],-20, -20, 20);
	
	window.img_pos_x = 250;
	window.img_pos_y = 250;
	(void)argc;
	printf("%f\n", M_PI);
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.size_x, window.size_y, *argv);
	print_os(&window);
	window.imp_ptr = mlx_new_image(window.mlx_ptr, window.img_width, window.img_height);
	window.img = (int *)mlx_get_data_addr(window.imp_ptr, &window.img_bpp, &window.img_size_line, &window.img_endian);
	printf("\n img bits_per_pixel - %d, size_line - %d, endian - %d\n", window.img_bpp, window.img_size_line, window.img_endian);
	set_teble(&window);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.imp_ptr, window.img_pos_x, window.img_pos_y);
	setup_controls(&window);
	mlx_loop(window.mlx_ptr);
	write(1, "\nfdfdfdf\n", 9);
	return (0);
}
