#include "../includes/ft_printf.h"

void	ft_init_len_and_neg_zero(int *len, char *number,
								t_flags fkit, int *zero_diff)
{
	*len = ft_strlen(number);
	*zero_diff = fkit.accuracy - *len;
	if ((*number) == '-')
	{
		(*zero_diff)++;
	}
}

void	ft_printing_spaces_after(t_flags fkit, int *space_diff, int *counter)
{
	if (fkit.f_minus == 1)
	{
		while (*space_diff > 0)
		{
			ft_putchar(' ');
			(*counter)++;
			(*space_diff)--;
		}
	}
}

int	ft_space_instead_zeronbr(t_flags fkit, int inbr, int len, int *counter)
{
	if (!inbr && fkit.accuracy < fkit.width && fkit.accuracy != -1
		&& fkit.accuracy < len)
	{
		ft_putchar(' ');
		(*counter)++;
		return (0);
	}
	return (1);
}

int	ft_space_instead_zerounsignednbr(t_flags fkit, unsigned int inbr,
									int len, int *counter)
{
	if (!inbr && fkit.accuracy < fkit.width && fkit.accuracy != -1
		&& fkit.accuracy < len)
	{
		ft_putchar(' ');
		(*counter)++;
		return (0);
	}
	return (1);
}
