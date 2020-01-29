/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecelsa <ecelsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:50:26 by ecelsa            #+#    #+#             */
/*   Updated: 2020/01/29 09:58:04 by ecelsa           ###   ########.fr       */
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
	int		size_x;
	int		size_y;
	int		y_c;
	int		x_c;
	int		ln;
	int		zoom;
	int		z;
	t_mevnt	mouse;
}				t_window;

t_ptr			*creat_pt();
void			free_ptr(t_ptr *ptr);
void			fil_ptr(t_ptr *ptr, char *str, int line);
void			fig_rotate(t_ptr *ptr, double rotx, double roty, double rotz);
void			rot_ptr(t_ptr *ptr, double x, double y, double z);

#endif
