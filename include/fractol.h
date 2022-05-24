#ifndef FRACTOL_H
#define FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>

//      void	*img;
//      char	*addr;
//      int		bits_per_pixel;
//      int		line_length;
//      int		endian;

typedef struct s_var
{
	//IMAGE VAR
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	void	*ptr;
	void	*mlx_win;
	double	x;
	double	y;
	//WINDOWS DEMENSIONS
	int		size_x;
	int		size_y;
	int		id_set;
	//MAP DEMENSION
	double	xp;
	double	xn;
	double	yp;
	double	yn;
	double	xm;
	double	ym;
	// Sequence variables
	int		itteration;
	// double	zp;
	// double	zn;
}	t_var;

void ft_mandelbrot(t_var *fractol);
#endif
