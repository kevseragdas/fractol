#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h> // silmeyi unutma
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

typedef struct s_complex
{
	double real;
	double im;
} t_complex;

typedef struct s_img
{
	void	*img_pointer;
	char	*pixel_pointer;
};

typedef struct s_fractal
{
	void	*mlx_connetion;
	void	*mlx_window;
};

int	ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
