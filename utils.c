/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:16:31 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/13 15:21:09 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_true_number(const char *s)
{
	int	i;
	int	dots;
	int	digits;

	i = 0;
	dots = 0;
	digits = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			digits++;
		else if (s[i] == '.')
			dots++;
		else
			return (0);
		i++;
	}
	return (digits && dots <= 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (0);
		i++;
	}
	return (1);
}

static double	make_dec(const char *arg)
{
	double	num;
	double	power;

	num = 0.0;
	power = 10.0;
	while (*arg >= '0' && *arg <= '9')
	{
		num += (*arg - '0') / power;
		power *= 10.0;
		arg++;
	}
	return (num);
}

double	atof(const char *arg)
{
	double	num;
	int		sign;

	num = 0.0;
	sign = 1;
	while (*arg == ' ' || (*arg >= 9 && *arg <= 13))
		arg++;
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (*arg >= '0' && *arg <= '9')
	{
		num = num * 10.0 + (*arg - '0');
		arg++;
	}
	if (*arg == '.')
		num += make_dec(++arg);
	return (num * sign);
}
