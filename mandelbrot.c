/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:41:36 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/12 14:55:21 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(t_complex c)
{
	t_complex	z;
	int			i;
	double		tmp;

	z.im = 0;
	z.re = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if ((z.re * z.re + z.im * z.im) > 4)
			break ;
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

static	void	get_pixel_complex(double *re, double *im, t_data *w, int pos)
{
	int		x;
	int		y;
	double	re_f;
	double	im_f;

	x = pos % WIDTH;
	y = pos / WIDTH;
	re_f = (w->max_re - w->min_re) / WIDTH;
	im_f = (w->max_im - w->min_im) / HEIGHT;
	*re = w->min_re + x * re_f;
	*im = w->max_im - y * im_f;
}

void	draw_mandelbrot(t_data *w)
{
	int		pos;
	int		iter;
	double	re;
	double	im;

	pos = 0;
	while (pos < WIDTH * HEIGHT)
	{
		get_pixel_complex(&re, &im, w, pos);
		iter = mandelbrot_iter((t_complex){re, im});
		my_mlx_pixel_put(w, pos % WIDTH, pos / HEIGHT, get_color(iter));
		pos++;
	}
}
