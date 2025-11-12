#include "fractol.h"

int	clean_exit(t_data *window)
{
	if (window->img)
		mlx_destroy_image(window->mlx, window->img);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return(0);
		i++;
	}
	return (1);
}

static int	close_window(void *param)
{
	t_data *window = (t_data *)param;
	clean_exit(window);
	return (0);
}

static 	void open_window(char s)
{
	t_data	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "Fractol");
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel, &window.line_len, &window.endian);
	if(s == 'm')
		draw_mandelbrot(&window);
	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);
	mlx_hook(window.win, 17, 0, close_window, NULL);
	mlx_loop(window.mlx);
}

int	get_color(int iter)
{
	int	red;
	int	green;
	int	blue;

	if (iter == 0)
		return (0x000000); 

	
	red = (iter * 8) % 255;
	green = (iter * 5) % 255;
	blue = (iter * 12) % 255;

	return (red << 16 | green << 8 | blue);
}

int main(int ac, char **arg)
{
	if(ac == 2 && ft_strncmp(arg[1], "mandelbrot", 10))
		open_window('m');
	else if( (ac == 4 && ft_strncmp(arg[1], "julia", 5)))
		open_window('j');
	else
		write(2, "Please enter \n\tmadelbrot or\n\tjulia value1 value2\n", 50);
	return(0);
}

