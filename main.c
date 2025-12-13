/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:41:47 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/13 16:16:54 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_type(t_data *window)
{
	if (window->set_type == 'm')
		draw_mandelbrot(window);
	else if (window->set_type == 'j')
		draw_julia(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

int	clean_exit(t_data *window)
{
	if (!window)
		exit(1);
	if (window->img)
		mlx_destroy_image(window->mlx, window->img);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	exit(0);
	return (0);
}

static void	open_window(char s, double re, double im)
{
	t_data	window;

	window.mlx = NULL;
	window.win = NULL;
	window.img = NULL;
	window.addr = NULL;
	init_mlx(&window);
	set_defaults(&window, s, re, im);
	fractal_type(&window);
	click_moves(&window);
	mlx_loop(window.mlx);
}

int	main(int ac, char **arg)
{
	t_complex	c;

	c.re = 0;
	c.im = 0;
	if (ac == 2 && ft_strncmp(arg[1], "mandelbrot", 10))
		open_window('m', 0, 0);
	else if ((ac == 4 && ft_strncmp(arg[1], "julia", 5)))
	{
		if (!is_true_number(arg[2]) || !is_true_number(arg[3]))
		{
			write(2, "*Please enter two valid julia coordinates.", 43);
			write(2, "*\n*\tExample: -0.7 0.27015\t\t  *\n", 32);
			return (1);
		}
		c.re = atof(arg[2]);
		c.im = atof(arg[3]);
		open_window('j', c.re, c.im);
	}
	else
	{
		write(2, "Please enter: \n\t*\t  mandelbrot\t\t*\n", 35);
		write(2, "\t*\t\tor\t\t*\n\t*julia <parameter1> <parameter2>*\n", 46);
	}
	return (0);
}
