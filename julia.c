#include "fractol.h"
#include <stdio.h>

int	julia_iter(t_complex z, t_complex c)
{
	int			i;
	double		tmp;

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

void	draw_julia(t_data *window)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;
	int			iter;
	double		re_factor;
	double		im_factor;

	printf("olumlu\n");
	c.re = window->julia_c_re;
	c.im = window->julia_c_im;
	re_factor = (window->max_re - window->min_re) / WIDTH;
	im_factor = (window->max_im - window->min_im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = window->min_re + x * re_factor;
			z.im = window->max_im - y * im_factor;
			iter = julia_iter(z, c);
			my_mlx_pixel_put(window, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}	