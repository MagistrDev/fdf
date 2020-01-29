/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:50:26 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 17:43:43 by ecelsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define ESC 53
# define SPACE 49
# define PLUS 69
# define MINUS 78

typedef struct	s_ptr
{
	double			x;
	double			y;
	double			z;
	double			x_o;
	double			y_o;
	double			z_o;
	int				color;
	struct s_ptr	*next;
}				t_ptr;

typedef struct	s_put_line
{
	float	dx;
	float	dy;
	float	xst;
	float	xend;
	float	yst;
	float	yend;
	int		c;
	int		l;
	int		i;
	double	a;
	double	b;
	int		y_c;
	int		x_c;
}				t_put_line;

typedef struct	s_mevnt
{
	int		prev_x;
	int		prev_y;
	int		x;
	int		y;
	int		btn;
}				t_mevnt;

typedef struct	s_img
{
	void	*img_ptr;
	int		*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}				t_img;

typedef struct	s_window
{
	t_ptr	*ptr;
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**argv;
	int		size_x;
	int		size_y;
	int		y_c;
	int		x_c;
	int		ln;
	int		zoom;
	int		z;
	int		r_x;
	int		r_y;
	int		r_z;
	int		x_max[2];
	int		y_max[2];
	t_mevnt	mouse;
}				t_window;

t_ptr			*creat_pt();
void			free_ptr(t_ptr *ptr);
void			fil_ptr(t_ptr *ptr, char *str, int line);
void			fig_rotate(t_ptr *ptr, double rotx, double roty, double rotz);
void			rot_ptr(t_ptr *ptr, double x, double y, double z);
int				cmp_1(t_ptr **pt, t_window *win);
void			fil_px(t_window *win, t_ptr **pt);
void			put_img(t_window *win, t_ptr *ptr);
void			vertat_os(t_window *win, int key);
int				key_press(int key, t_window *win);
void			ft_putline(t_ptr *pt1, t_ptr *pt2, int col, t_window *win);
void			fil_window(t_window *win);
void			input_arg(int argc, char **argv, t_window *win);
void			help_smile(t_put_line *pl);
#endif
