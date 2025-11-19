#include "fractol.h"

int	is_valid_number(const char *str)
{
	int	i;
	int	dots;
	int	digits;

	i = 0;
	dots = 0;
	digits = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i++])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digits++;
		else if (str[i] == '.')
			dots++;
		else
			return (0);
	}
	if (dots > 1)
		return (0);
	if (digits == 0) 
		return (0);
	return (1);
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
double atof(const char *arg)
{
	double	res;
	double	power;
	int		sign;

	res = 0.0;
	power = 1.0;
	sign = 1;
	while (*arg == ' ' || (*arg >= 9 && *arg <= 13))
		arg++;
	if (*arg == '-')
		sign = -1;
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg >= '0' && *arg <= '9')
	{
		res = res * 10.0 + (*arg - '0');
		arg++;
	}
	if (*arg == '.')
	{
		arg++;
		while (*arg >= '0' && *arg <= '9')
		{
			res = res + (*arg - '0') / (power * 10.0);
			power *= 10.0;
			arg++;
		}
	}
	return (res * sign);
}