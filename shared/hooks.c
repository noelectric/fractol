/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:09:33 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/06/23 21:42:05 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	v_arrow(int	keycode, t_var *var, double mov)
{
	if (keycode == DOWN_ARROW)
	{
		var->min.y += -mov;
		var->max.y += -mov;
	}
	else
	{
		var->min.y += mov;
		var->max.y += mov;
	}
}

void	h_arrow(int	keycode, t_var *var, double mov)
{
	if (keycode == RIGHT_ARROW)
	{
		var->min.x += -mov;
		var->max.x += -mov;
	}
	else
	{
		var->min.x += mov;
		var->max.x += mov;
	}
}

int		keys_move(int keycode, t_var *var)
{
	double	mov;

	if (keycode >= LEFT_ARROW && keycode <= UP_ARROW)
	{
		mov = 10 * fabs(var->max.x - var->min.x) / 60;
		if (keycode == DOWN_ARROW || keycode == UP_ARROW)
			v_arrow(keycode, var, mov);
		else
			h_arrow(keycode, var, mov);
		clear_and_draw(var);
	}
	return (0);
}

void	keys(int keycode, t_var *var)
{
	if (keycode == M)
		var->id_set = 1;
	if (keycode == A)
		var->id_set = 2;
	if (keycode == V)
		var->bpp = 1;
	if (keycode == B)
		var->bpp = 0;
	if (keycode == J)
		julia(var);
	if (keycode == T)
		julia1(var);
	if (keycode == Y)
		julia2(var);
	if (keycode == U)
		julia3(var);
	clear_and_draw(var);
}

int		keys_hook(int keycode, t_var *var)
{
	keys(keycode, var);
	if (keycode == Q)
		var->color = 0x2211FF;
	if (keycode == W)
		var->color = 0xFFFFFF;
	if (keycode == E)
		var->color = 0xff2105;
	if (keycode == ESC)
		exit_hook(var);
	if (keycode == C)
	{
		var->max.x = 2;
		var->min.x = -2;
		var->max.y = 2;
		var->min.y = -2;
		var->itr = 250;
		var->color = 0xFFFFFF;
		clear_and_draw(var);
	}
	return (keys_move(keycode, var));
}
