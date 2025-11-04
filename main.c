#include "fractol.h"

int main(int ac, char **arg)
{
	if(ac == 2 && ft_strncmp(arg[1], "mandelbrot", 10)
		|| ac == 4 && ft_strncmp(arg[1], "julia", 5))
	{
		void *mlx;
		void *win;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 800, 800, "Fractol");
		mlx_hook(win, 17, 0, close_window, NULL);
		mlx_loop(mlx);
	}
	else
	{
		write(2, "Please enter \n\tmadelbrot or\n", 29);
		write(2, "\tjulia value1 value2\n", 22);
	}
	return(0);
}

int	close_window(void *param)
{
	(void)param; 
	exit(0);
	return (0);
}