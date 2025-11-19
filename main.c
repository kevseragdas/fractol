#include "fractol.h"

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

int	close_window(void *param)
{
	t_data *window;

	window = (t_data *)param;
	clean_exit(window);
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
	init_fractal_vars(&window, s, re, im);
	redraw_fractal(&window);
	register_hooks(&window);
	mlx_loop(window.mlx);
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

int main(int ac, char **arg)
{
	t_complex c;

	c.re = 0;
	c.im = 0;
	if(ac == 2 && ft_strncmp(arg[1], "mandelbrot", 10))
		open_window('m', 0, 0);
	else if( (ac == 4 && ft_strncmp(arg[1], "julia", 5)))
	{
		if (!is_valid_number(arg[2]) || !is_valid_number(arg[3]))
		{
			write(2, "Please enter double type julia points\n", 39);
			return (1);
		}
		c.re = atof(arg[2]);
		c.im = atof(arg[3]);
		open_window('j', c.re, c.im);
	}
	else
		write(2, "Please enter \n\tmadelbrot or\n\tjulia value1 value2\n", 50);
	return(0);
}

