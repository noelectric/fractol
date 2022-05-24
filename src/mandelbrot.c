#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

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
	//WINDOWS DEMENSIONS
	int		size_x;
	int		size_y;
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

int	ft_close ()
{
	exit(0);
}

int	result (t_var *var)
{
	int	itteration;
	double	zp;
	double	zn;
	double	tmp;

	itteration = 0;
	zp = 0;
	zn = 0;
	while (itteration < var->itteration && (zp*zp + zn*zn) < 4)
	{
		tmp = zp;
		zp = zp*zp - zn*zn + var->xm;
		zn = 2 * tmp * zn + var->ym;
		itteration++;
	}
	return (itteration);
}

void	draw_mandelbrot(t_var *var)
{
	int	i;
	int	j;
	int	res;
	int	*position;

	i = 0;
	j = 0;
	while (j < var->size_y)
	{
		i = 0;
		var->ym = var->yn + j * (var->yp - var->yn) / var->size_y;
		while (i < var->size_x)
		{
			var->xm = var->xn + i * (var->xp - var->xn) / var->size_x;
			res = result(var);
			position = (int *)(var->addr + (j * var->size_x * 4 + i * 4));
			if (var->itteration != res)
				*position = res * var->color;
			else
				*position = 0x00000000;
			i++;
		}
		j++;
	}
}

void	clear_and_draw(t_var *fr)
{
	mlx_destroy_image(fr->ptr, fr->img);
	fr->img = mlx_new_image(fr->ptr, fr->size_x, fr->size_y);
	mlx_clear_window(fr->ptr, fr->mlx_win);
	draw_mandelbrot(fr);
	mlx_put_image_to_window(fr->ptr, fr->mlx_win, fr->img, 0, 0);
}

int	mouse_hook(int keycode, int x, int y, t_var *var)
{
	t_var	cord;
	printf("|x| = %d, |y| = %d\n", x, y);
	cord.xp = var->xn + (double)x * (var->xp - var->xn) / var->size_x;
	cord.yp = var->yn + (double)y * (var->yp - var->yn) / var->size_y;
	// printf("|x| = %f, |y| = %f\n", cord.xp, cord.yp);
	if (keycode == 4)
	{
		var->itteration += 2;
		var->xp = cord.xp + (var->xp - cord.xp) * 0.9;
		var->xn = cord.xp + (var->xn - cord.xp) * 0.9;
		var->yp = cord.yp + (var->yp - cord.yp) * 0.9;
		var->yn = cord.yp + (var->yn - cord.yp) * 0.9;
	}
	if (keycode == 5)
	{
		var->itteration -= 2;
		var->xp = cord.xp + (var->xp - cord.xp) * 1.1;
		var->xn = cord.xp + (var->xn - cord.xp) * 1.1;
		var->yp = cord.yp + (var->yp - cord.yp) * 1.1;
		var->yn = cord.yp + (var->yn - cord.yp) * 1.1;
	}
	clear_and_draw(var);
	return 0;
}

int main(void)
{
	t_var	var;

	var.xp = 2;
	var.xn = -2;
	var.yp = 2;
	var.yn = -2;
	var.color = 0xFFFFFF;
	var.itteration = 250;
	var.ptr = mlx_init();
	var.size_x = 500;
	var.size_y = 500;
	var.mlx_win = mlx_new_window(var.ptr, var.size_x, var.size_y, "Fractal");
	var.img = mlx_new_image(var.ptr, var.size_x, var.size_y);
	var.addr = mlx_get_data_addr(var.img, &var.bits_per_pixel, &var.line_length, &var.endian);

	draw_mandelbrot(&var);

	mlx_put_image_to_window(var.ptr, var.mlx_win, var.img, 0, 0);
	mlx_hook(var.mlx_win, 17, 0, &ft_close, &var);
	mlx_hook(var.mlx_win, 4, 0, &mouse_hook, &var);
	// mlx_hook(mlx_win, 6, 0, &ft_close, &var);
	mlx_loop(var.ptr);
}
