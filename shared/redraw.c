/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:44:10 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/06/23 21:22:05 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		exit_hook(t_var *var)
{
	mlx_destroy_image(var->mlx_ptr, var->img_ptr);
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	mlx_destroy_window(var->mlx_ptr, var->win_ptr);
	exit(0);
}

void	clear_and_draw(t_var *var)
{
	mlx_destroy_image(var->mlx_ptr, var->img_ptr);
	var->img_ptr = mlx_new_image(var->mlx_ptr, 500, 500);
	mlx_clear_window(var->mlx_ptr, var->win_ptr);
	if (var->id_set == 0)
		draw_julia(var);
	if (var->id_set == 1)
		draw_mandelbrot(var);
	if (var->id_set == 2)
		draw_noelectric(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
}

int		mouse_move(int x, int y, t_var *var)
{
	if (var->id_set == 0 && var->bpp)
	{
		var->zoom.x = var->min.x + ((double)x * (var->max.x - var->min.x)) / 500;
		var->zoom.y = var->min.y + ((double)y * (var->max.y - var->min.y)) / 500;
		clear_and_draw(var);
	}
	return (0);
}

void	zoom(int x, int y, t_var *var, double z)
{
	t_cord m;

	m.x = var->min.x + ((double)x * (var->max.x - var->min.x)) / 500;
	m.y = var->min.y + ((double)y * (var->max.y - var->min.y)) / 500;
	var->min.x = m.x + (var->min.x - m.x) * z;
	var->max.x = m.x + (var->max.x - m.x) * z;
	var->min.y = m.y + (var->min.y - m.y) * z;
	var->max.y = m.y + (var->max.y - m.y) * z;
}

int		mouse_hook(int m, int x, int y, t_var *var)
{
	if (m == 4)
	{
		var->itr += 2;
		zoom(x, y, var, 0.90);
	}
	if (m == 5 && fabs(var->max.x - var->min.x) <= 5)
	{
		var->itr -= 2;
		zoom(x, y, var, 1.10);
	}
	clear_and_draw(var);
	return (0);
}
