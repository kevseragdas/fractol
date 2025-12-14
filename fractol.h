/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:42:16 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/14 18:33:14 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define KEY_ESC 65307
# define MAX_ITER 1000

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	double	julia_c_im;
	double	julia_c_re;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	char	set_type;
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
int		julia_iter(double z_re, double z_im, double c_re, double c_im);
void	draw_julia(t_data *window);
int		is_true_number(const char *str);
double	atof(const char *arg);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	click_moves(t_data *window);
void	set_defaults(t_data *window, char s, double re, double im);
void	init_mlx(t_data *window);
int		mouse_handler(int button, int x, int y, t_data *window);
int		key_handler(int keycode, t_data *window);
int		clean_exit(t_data *window);
void	fractal_type(t_data *window);
void	ft_error(void);

#endif
