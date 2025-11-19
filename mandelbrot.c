#include "fractol.h"

int	mandelbrot_iter(t_complex c)
{
	t_complex	z;
	int			i;
	double		tmp;

	z.im = 0;
	z.re = 0;
	i = 0;
	while (i < 42)
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

void	draw_mandelbrot(t_data *window)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;
	double		re_factor;
	double		im_factor;

	re_factor = (window->max_re - window->min_re) / WIDTH;
	im_factor = (window->max_im - window->min_im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = window->min_re + x * re_factor;
			c.im = window->max_im - y * im_factor;
			iter = mandelbrot_iter(c);
			my_mlx_pixel_put(window, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}