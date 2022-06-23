/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:18:54 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/06/23 21:13:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_error(void)
{
	ft_putendl("/**********************************************/");
	ft_putendl("/*         Usage : ./fractol <...>            */");
	ft_putendl("/**********************************************/");
	ft_putendl("/*                   --> Julia                */");
	ft_putendl("/*                   --> Mandelbrot           */");
	ft_putendl("/*                   --> NoElectric           */");
	ft_putendl("/**********************************************/");
}

int	fractol(int id)
{
	t_var	var;

	var.id_set = id;
	var.color = 0xFFFFFF;
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, 500, 500, "Fractol");
	var.img_ptr = mlx_new_image(var.mlx_ptr, 500, 500);
	var.mlx_addr = (int *)mlx_get_data_addr(var.img_ptr, &var.bpp, &var.line_length, &var.endian);
	if (id == 0)
		ft_julia(&var);
	if (id == 1)
		ft_mandelbrot(&var);
	if (id == 2)
		ft_noelectric(&var);
	mlx_put_image_to_window(var.img_ptr, var.win_ptr, var.img_ptr, 0, 0);
	mlx_hook(var.win_ptr, KEYPRESS, SHIFTMAASK_1, keys_hook, &var);
	mlx_hook(var.win_ptr, BUTTONPRESS, SHIFTMAASK_0, mouse_hook, &var);
	mlx_hook(var.win_ptr, MOTIONNOTIFY, SHIFTMAASK_0, mouse_move, &var);
	mlx_hook(var.win_ptr, DESTRYNOTIFY, SHIFTMAASK_0, exit_hook, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!ft_strncmp(av[1], "Julia", 5))
			return (fractol(0));
		if (!ft_strncmp(av[1], "Mandelbrot", 10))
			return (fractol(1));
		if (!ft_strncmp(av[1], "Noelectric", 10))
			return (fractol(2));
	}
	ft_error();
	return (0);
}
