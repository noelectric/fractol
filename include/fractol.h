/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:19:22 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/06/23 21:12:49 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "/usr/local/include/mlx.h"

# define ESC 			53
# define A 				0
# define B 				11
# define C 				8
# define D 				2
# define E				14
# define F 				3
# define G 				5
# define H 				4
# define I 				34
# define J 				38
# define K 				40
# define L 				37
# define M 				46
# define N 				45
# define O 				31
# define P 				35
# define Q 				12
# define R 				15
# define S 				1
# define T 				17
# define U 				32
# define V 				9
# define W 				13
# define X 				7
# define Y 				16
# define Z 				6
# define LEFT_ARROW		123
# define RIGHT_ARROW	124
# define DOWN_ARROW		125
# define UP_ARROW		126
# define KEYPRESS		2
# define BUTTONPRESS	4
# define MOTIONNOTIFY	6
# define DESTRYNOTIFY	17
# define SHIFTMAASK_0	0
# define SHIFTMAASK_1	1

typedef struct			s_cord
{
	double				x;
	double				y;
}						t_cord;

typedef struct			s_var
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*mlx_addr;
	int					bpp;
	int					line_length;
	int					endian;
	int					id_set;
	int					color;
	int					itr;
	t_cord				convert;
	t_cord				zoom;
	t_cord				min;
	t_cord				max;
}						t_var;

void	ft_putendl(char const *s);
int		ft_strncmp( const char *s1, const char *s2, size_t length);
int		ft_mandelbrot(t_var *var);
int		ft_julia(t_var *var);
int		mouse_hook(int m, int x, int y, t_var *var);
void	zoom(int x, int y, t_var *var, double z);
void	clear_and_draw(t_var *var);
void	draw_mandelbrot(t_var *fr);
void	draw_julia(t_var *var);
int		mouse_move(int x, int y, t_var *var);
int		keys_hook(int keycode, t_var *var);
int		exit_hook(t_var *var);
void	julia(t_var *var);
void	julia1(t_var *var);
void	julia2(t_var *var);
void	julia3(t_var *var);
int		ft_noelectric(t_var *var);
void	draw_noelectric(t_var *fr);

#endif
