#include "../includes/ft_printf.h"

t_flags	ft_flag_minus(t_flags fkit)
{
	fkit.f_minus = 1;
	fkit.f_zero = 0;
	return (fkit);
}

t_flags	ft_flag_width(t_flags fkit, char *work_str, int *i)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(work_str[*i]))
	{
		nbr = nbr * 10 + (work_str[*i] - 48);
		(*i)++;
	}
	fkit.width = nbr;
	return (fkit);
}

t_flags	ft_flag_argwidth(t_flags fkit, va_list args, int *i)
{
	fkit.width = va_arg(args, int);
	if (fkit.width < 0)
	{
		fkit.width = -fkit.width;
		fkit.f_minus = 1;
	}
	(*i)++;
	return (fkit);
}

t_flags	ft_flag_accuracy(t_flags fkit, char *work_str, int *i)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(work_str[*i]))
	{
		nbr = nbr * 10 + (work_str[*i] - 48);
		(*i)++;
	}
	fkit.accuracy = nbr;
	return (fkit);
}

t_flags	ft_flag_argaccuracy(t_flags fkit, va_list args, int *i)
{
	fkit.accuracy = va_arg(args, int);
	if (fkit.accuracy < 0)
	{
		fkit.accuracy = -1;
	}
	(*i)++;
	return (fkit);
}
