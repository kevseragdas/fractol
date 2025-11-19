#include "fractol.h"

void	handle_pan(int keycode, t_data *window)
{
	double	range_re;
	double	range_im;

	range_re = (window->max_re - window->min_re) * 0.1;
	range_im = (window->max_im - window->min_im) * 0.1;
	if (keycode == KEY_LEFT)
	{
		window->min_re -= range_re;
		window->max_re -= range_re;
	}
	else if (keycode == KEY_RIGHT)
	{
		window->min_re += range_re;
		window->max_re += range_re;
	}
	else if (keycode == KEY_UP)
	{
		window->min_im += range_im;
		window->max_im += range_im;
	}
	else if (keycode == KEY_DOWN)
	{
		window->min_im -= range_im;
		window->max_im -= range_im;
	}
}

int	key_press_hook(int keycode, t_data *window)
{
	if (keycode == KEY_ESC)
		clean_exit(window);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_UP || keycode == KEY_DOWN)
	{
		handle_pan(keycode, window);
		redraw_fractal(window);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *window)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	if (button == MOUSE_SCROLL_UP)
		zoom_factor = 1.1;
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_factor = 0.9;
	else
		return (0);
	mouse_re = window->min_re + (x * (window->max_re - window->min_re) / WIDTH);
	mouse_im = window->max_im - (y * (window->max_im - window->min_im) / HEIGHT);
	window->min_re = (window->min_re - mouse_re) / zoom_factor + mouse_re;
	window->max_re = (window->max_re - mouse_re) / zoom_factor + mouse_re;
	window->min_im = (window->min_im - mouse_im) / zoom_factor + mouse_im;
	window->max_im = (window->max_im - mouse_im) / zoom_factor + mouse_im;
	redraw_fractal(window);
	return (0);
}

void	init_fractal_vars(t_data *window, char s, double re, double im)
{
	window->set_type = s;
	window->julia_c_re = re;
	window->julia_c_im = im;
	if (s == 'm')
	{
		window->min_re = M_MIN_RE;
		window->max_re = M_MAX_RE;
		window->min_im = M_MIN_IM;
		window->max_im = M_MAX_IM;
	}
	else
	{
		window->min_re = J_MIN_RE;
		window->max_re = J_MAX_RE;
		window->min_im = J_MIN_IM;
		window->max_im = J_MAX_IM;
	}
}

void	register_hooks(t_data *window)
{
	mlx_hook(window->win, 17, 0, close_window, window);
	mlx_hook(window->win, 2, 1L << 0, key_press_hook, window);
	mlx_hook(window->win, 4, 1L << 2, mouse_hook, window);
}