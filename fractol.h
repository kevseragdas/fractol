#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"


# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_comp
{
	double	re;
	double	im;
}	t_complex;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		mandelbrot_iter(t_complex c);
void	draw_mandelbrot(t_data *window);
int		get_color(int iter);
#endif
