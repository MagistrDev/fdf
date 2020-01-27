/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:09:09 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/27 23:23:38 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

int key_press(int key, t_window *param)
{
	t_window win;

	win = *param;
	ft_putchar(key);
	mlx_pixel_put(win.mlx_ptr, win.win_ptr, key, key, 0xffffff);
	ft_putnbr(key);
	ft_putstr(" ");
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
		for (int hop = 0;hop < elem;hop++)
			fig_rotate(&g_fig[hop], g_rx, g_ry, g_rz);
				
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
	win->mouse.prev_x = win->mouse.x;
	
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
}