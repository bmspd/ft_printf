#include "../includes/ft_printf.h"

static void	printing_number(unsigned long int number)
{
	char	*base;

	base = "0123456789abcdef";
	if (number >= 16)
	{
		printing_number(number / 16);
		printing_number(number % 16);
	}
	else
	{
		write(1, &base[number], 1);
	}
}

static int	number_len_hex(unsigned long int number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number = number / 16;
		i++;
	}
	return (i);
}

static void	minzer_printzero(t_flags fkit, int space_diff
							, int diff, int *counter)
{
	if (fkit.f_minus == 0)
	{
		while (space_diff > 0)
		{
			ft_putchar(' ');
			(*counter)++;
			space_diff--;
		}
	}
	ft_putstr("0x");
	while (diff-- > 0)
	{
		ft_putchar('0');
		(*counter)++;
	}
}

static void	minone(t_flags fkit, int space_diff, int *counter)
{
	if (fkit.f_minus == 1)
	{
		while (space_diff > 0)
		{
			ft_putchar(' ');
			(*counter)++;
			space_diff--;
		}
	}
}

void	ft_pointer_behaviour(t_flags fkit, va_list args, int *counter)
{
	unsigned long int	number;
	int					len;
	int					diff;
	int					space_diff;

	number = va_arg(args, unsigned long int);
	len = number_len_hex(number);
	if (!number)
		len = 1;
	*counter = *counter + len + 2;
	diff = fkit.accuracy - len;
	if (fkit.accuracy == -1)
		space_diff = fkit.width - len - 2;
	else
		space_diff = fkit.width - fkit.accuracy - len - 2;
	minzer_printzero(fkit, space_diff, diff, counter);
	printing_number(number);
	minone(fkit, space_diff, counter);
}
