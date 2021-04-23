#include "../includes/ft_printf.h"
static void	ft_zer_min_width(t_flags fkit, int len, int *counter)
{
	int	i;

	i = 0;
	if (fkit.f_minus == 0 && fkit.f_zero == 1)
	{
		while (i++ < fkit.width - fkit.accuracy - len)
		{
			ft_putchar('0');
			(*counter)++;
		}
	}
	else if (fkit.f_minus == 0 && fkit.f_zero == 0)
	{
		while (i++ < fkit.width - fkit.accuracy - len)
		{
			ft_putchar(' ');
			(*counter)++;
		}
	}
}

static void	ft_havemin(t_flags fkit, int len, int *counter)
{
	int	i;

	i = 0;
	if (fkit.f_minus == 1)
	{
		while (i++ < fkit.width - fkit.accuracy - len)
		{
			ft_putchar(' ');
			(*counter)++;
		}
	}
}

void	ft_string_behaviour(t_flags fkit, va_list args, int *counter)
{
	int		i;
	char	*work_string;
	int		len;

	work_string = va_arg(args, char *);
	if (!work_string || work_string == 0)
		work_string = "(null)";
	len = (int) ft_strlen(work_string);
	i = 0;
	if (fkit.accuracy < len && fkit.accuracy >= 0)
		len = fkit.accuracy;
	if (fkit.accuracy == -1 || len <= fkit.accuracy)
		fkit.accuracy = 0;
	ft_zer_min_width(fkit, len, counter);
	i = 0;
	while (i < len)
	{
		ft_putchar(work_string[i]);
		(*counter)++;
		i++;
	}
	ft_havemin(fkit, len, counter);
}
