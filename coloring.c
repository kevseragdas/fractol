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
	int	red;
	int	green;
	int	blue;
	if (iter == MAX_ITER || iter == 0)
			return (0x000000);
	red = (iter * 9) % 255;
	green = (iter * 5) % 255;
	blue = (iter * 15) % 255;
	return (red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}