#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int    mandelbrot_iter(t_complex c)
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
void draw_mandelbrot(t_data *window)
{
    int			x;
	int			y;
	t_complex	c;
	int			iter;
	double		re_factor;
	double		im_factor;

	re_factor = 3.0 / WIDTH;
	im_factor = 3.0 / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = -2.0 + x * re_factor;
			c.im = -1.5 + y * im_factor;
			iter = mandelbrot_iter(c);
			my_mlx_pixel_put(window, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}
