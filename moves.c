/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:41:19 by kagdas            #+#    #+#             */
/*   Updated: 2025/11/25 15:41:19 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_data *win)
{
	if (key == KEY_ESC)
		clean_exit(win);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_data *win)
{
	double	m_r;
	double	m_i;

	if (button == 4)
	{
		m_r = win->min_re + (x * (win->max_re - win->min_re) / WIDTH);
		m_i = win->max_im - (y * (win->max_im - win->min_im) / HEIGHT);
		win->min_re = m_r + (win->min_re - m_r) / 1.1;
		win->max_re = m_r + (win->max_re - m_r) / 1.1;
		win->min_im = m_i + (win->min_im - m_i) / 1.1;
		win->max_im = m_i + (win->max_im - m_i) / 1.1;
	}
	else if (button == 5)
	{
		m_r = win->min_re + (x * (win->max_re - win->min_re) / WIDTH);
		m_i = win->max_im - (y * (win->max_im - win->min_im) / HEIGHT);
		win->min_re = m_r + (win->min_re - m_r) / 0.9;
		win->max_re = m_r + (win->max_re - m_r) / 0.9;
		win->min_im = m_i + (win->min_im - m_i) / 0.9;
		win->max_im = m_i + (win->max_im - m_i) / 0.9;
	}
	else
		return (0);
	fractal_type(win);
	return (0);
}

void	set_defaults(t_data *win, char type, double c_re, double c_im)
{
	win->set_type = type;
	win->julia_c_re = c_re;
	win->julia_c_im = c_im;
	if (type == 'm')
	{
		win->min_re = M_MIN_RE;
		win->max_re = M_MAX_RE;
		win->min_im = M_MIN_IM;
		win->max_im = M_MAX_IM;
	}
	else
	{
		win->min_re = J_MIN_RE;
		win->max_re = J_MAX_RE;
		win->min_im = J_MIN_IM;
		win->max_im = J_MAX_IM;
	}
}

void	click_moves(t_data *win)
{
	mlx_hook(win->win, 17, 0, clean_exit, win);
	mlx_hook(win->win, 2, 1L << 0, key_handler, win);
	mlx_hook(win->win, 4, 1L << 2, mouse_handler, win);
}
