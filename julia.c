/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:41:55 by kagdas            #+#    #+#             */
/*   Updated: 2025/11/25 15:41:55 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double z_re, double z_im, double c_re, double c_im)
{
	int			i;
	double		tmp;

	i = 0;
	while (i < MAX_ITER)
	{
		if ((z_re * z_re + z_im * z_im) > 4)
			break ;
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		i++;
	}
	return (i);
}

void	draw_julia(t_data *w)
{
	int		pos;
	int		iter;
	double	re;
	double	im;

	pos = 0;
	while (pos < WIDTH * HEIGHT)
	{
		re = w->min_re + (pos % WIDTH) * ((w->max_re - w->min_re) / WIDTH);
		im = w->max_im - (pos / HEIGHT) * ((w->max_im - w->min_im) / HEIGHT);
		iter = julia_iter(re, im, w->julia_c_re, w->julia_c_im);
		my_mlx_pixel_put(w, pos % WIDTH, pos / HEIGHT, get_color(iter));
		pos++;
	}
}
