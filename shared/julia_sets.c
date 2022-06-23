/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:45:32 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/06/23 03:46:29 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_var *var)
{
	var->zoom.x = 0.285;
	var->zoom.y = 0.01;
	var->max.x = 2;
	var->min.x = -2;
	var->max.y = 2;
	var->min.y = -2;
	var->itr = 250;
	var->id_set = 0;
	var->bpp = 1;
}

void	julia1(t_var *var)
{
	var->zoom.x = 0.3;
	var->zoom.y = 0.5;
	var->max.x = 2;
	var->min.x = -2;
	var->max.y = 2;
	var->min.y = -2;
	var->itr = 250;
	var->id_set = 0;
	var->bpp = 1;
}

void	julia2(t_var *var)
{
	var->zoom.x = -0.038088;
	var->zoom.y = 0.9754633;
	var->max.x = 2;
	var->min.x = -2;
	var->max.y = 2;
	var->min.y = -2;
	var->itr = 250;
	var->id_set = 0;
	var->bpp = 1;
}

void	julia3(t_var *var)
{
	var->zoom.x = -0.4;
	var->zoom.y = 0.6;
	var->max.x = 2;
	var->min.x = -2;
	var->max.y = 2;
	var->min.y = -2;
	var->itr = 250;
	var->id_set = 0;
	var->bpp = 1;
}
