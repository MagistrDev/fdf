/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:04:32 by ecelsa            #+#    #+#             */
/*   Updated: 2019/12/10 11:50:35 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ESC 65307
# define SPACE 32
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ENTER 65293
# define TAB 65289
# define ABS(v) ((v) >= 0) ? v : -(v)

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_ptr
{
	double x;
	double y;
	double z;

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
	t_mevnt	mouse;
} 				t_window;

extern int g_rx;
extern int g_ry;
extern int g_rz;
extern t_ptr g_fig[100];
extern int elem;


void ft_putchar(char c);
void fig_rotate(t_ptr *ptr, double rot_x, double rot_y, double rot_z);
void print_os(t_window *window);
void set_teble(t_window *win);
void input_pt(t_ptr *pt, double x, double y, double z);
void ft_putline(t_ptr pt1, t_ptr pt2, int col, t_window *win);

int		key_press(int key, t_window *param);
int mouse_move(int x, int y, void *param);
int mouse_press(int button, int x, int y, void *param);
int mouse_release(int button, int x, int y, void *param);
int mouse_hook(int button, int x, int y, void *param);
void setup_controls(void *param);
#endif