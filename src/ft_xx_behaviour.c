#include "../includes/ft_printf.h"

static void	choose_spacediff(t_flags fkit, int *space_diff,
							int *zero_diff, int len)
{
	if (fkit.accuracy > len)
		*space_diff = fkit.width - len - *zero_diff;
	else if (fkit.accuracy < len)
		*space_diff = fkit.width - len;
	else
		*space_diff = fkit.width - fkit.accuracy;
}

static void	put_spaces(t_flags fkit, int *space_diff, int *counter)
{
	if ((fkit.f_minus == 0 && fkit.f_zero == 0)
		|| (fkit.f_zero == 1 && fkit.accuracy != -1))
	{
		while (*space_diff > 0)
		{
			if (fkit.f_minus == 1)
				break ;
			ft_putchar(' ');
			(*counter)++;
			(*space_diff)--;
		}
	}
}

static void	negative_nbr_condition(char **number, int *counter)
{
	if ((**number) == '-')
	{
		ft_putchar('-');
		(*number)++;
		(*counter)++;
	}
}

static void	put_zero(t_flags fkit, int *zero_diff, int *counter, int len)
{
	if ((fkit.f_minus == 0 && fkit.f_zero == 1) || fkit.accuracy > 0)
	{
		if (fkit.accuracy == -1)
			*zero_diff = fkit.width - len;
		while (*zero_diff > 0)
		{
			ft_putchar('0');
			(*counter)++;
			(*zero_diff)--;
		}
	}
}

void	ft_xx_behaviour(t_flags fkit, va_list args, int *counter, char *temp)
{
	char				*number;
	unsigned int		inbr;
	int					zero_diff;
	int					space_diff;
	int					len;

	inbr = (va_arg(args, unsigned int));
	number = ft_itoa_uxx(inbr);
	temp = number;
	ft_init_len_and_neg_zero(&len, number, fkit, &zero_diff);
	choose_spacediff(fkit, &space_diff, &zero_diff, len);
	put_spaces(fkit, &space_diff, counter);
	negative_nbr_condition(&number, counter);
	put_zero(fkit, &zero_diff, counter, len);
	while (*number)
	{
		if (!ft_space_instead_zerounsignednbr(fkit, inbr, len, counter))
			break ;
		if (!inbr && fkit.width == 0 && fkit.accuracy == 0)
			break ;
		ft_putchar(*(number++));
		(*counter)++;
	}
	free(temp);
	ft_printing_spaces_after(fkit, &space_diff, counter);
}
