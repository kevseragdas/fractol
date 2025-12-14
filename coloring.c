/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:42:24 by kagdas            #+#    #+#             */
/*   Updated: 2025/11/25 15:42:24 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_data *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		clean_exit(window);
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Fractol");
	if (!window->win)
		clean_exit(window);
	window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!window->img)
		clean_exit(window);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_len, &window->endian);
	if (!window->addr)
		clean_exit(window);
}

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (iter * 0x0F0205);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
