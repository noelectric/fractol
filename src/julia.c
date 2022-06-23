/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:27:51 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/06/23 20:35:58 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_iteration(int itr, float x, float y, t_cord cord)
{
	int		i;
	t_cord	z;
	double	old_real_nbr;

	i = 0;
	z.x = x;
	z.y = y;
	while ((i < itr) && ((z.x * z.x + z.y * z.y) <= 4))
	{
		old_real_nbr = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + cord.x;
		z.y = (2 * old_real_nbr * z.y) + cord.y;
		i = i + 2;
	}
	return (i);
}

void		draw_julia(t_var *var)
{
	int			i;
	int			j;
	int			res;
	t_cord		cord;

	j = 0;
	while (j <= 500)
	{
		i = 0;
		cord.y = var->min.y + (j * (var->max.y - var->min.y)) / 500;
		while (i <= 500)
		{
			cord.x = var->min.x + (i * (var->max.x - var->min.x)) / 500;
			res = check_iteration(var->itr, cord.x, cord.y, var->zoom);
			if (res != var->itr)
				var->mlx_addr[(j * 500) + i] = res * var->color;
			else
				var->mlx_addr[(j * 500) + i] = 0x000000;
			i++;
		}
		j++;
	}
}

int			ft_julia(t_var *var)
{
	var->zoom.x = 0.285;
	var->zoom.y = 0.01;
	var->max.x = 2;
	var->min.x = -2;
	var->max.y = 2;
	var->min.y = -2;
	var->itr = 250;
	var->bpp = 1;
	draw_julia(var);
	return (0);
}
