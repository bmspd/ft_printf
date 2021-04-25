#include "../includes/ft_printf.h"
static void	zero_min_condition(t_flags fkit, int *i, int *counter)
{
	if (fkit.width > 0 && fkit.f_zero == 1 && fkit.f_minus == 0)
	{
		while ((*i)++ < fkit.width - 1)
		{
			ft_putchar('0');
			(*counter)++;
		}
	}
	if (fkit.width > 0 && fkit.f_zero == 0 && fkit.f_minus == 0)
	{
		while ((*i)++ < fkit.width - 1)
		{
			ft_putchar(' ');
			(*counter)++;
		}
	}
}

void	ft_perc_behaviour(t_flags fkit, va_list args, int *counter)
{
	int		i;
	char	work_char;

	i = 0;
	work_char = '%';
	zero_min_condition(fkit, &i, counter);
	ft_putchar(work_char);
	(void)args;
	(*counter)++;
	if (fkit.width > 0 && fkit.f_minus == 1)
	{
		while (i++ < fkit.width - 1)
		{
			ft_putchar(' ');
			(*counter)++;
		}
	}
}
