#include "../includes/ft_printf.h"

t_flags	ft_type(t_flags fkit, char work_char)
{
	fkit.type = work_char;
	return (fkit);
}

void	ft_choosingtype(t_flags fkit, va_list args, int *counter)
{
	char	*temp;

	temp = NULL;
	if (fkit.type == '%')
	{
		ft_perc_behaviour(fkit, args, counter);
	}
	else if (fkit.type == 'c')
		ft_char_behaviour(fkit, args, counter);
	else if (fkit.type == 's')
		ft_string_behaviour(fkit, args, counter);
	else if (fkit.type == 'p')
		ft_pointer_behaviour(fkit, args, counter);
	else if (fkit.type == 'd' || fkit.type == 'i')
		ft_digit_behaviour(fkit, args, counter, temp);
	else if (fkit.type == 'u')
		ft_unsignedint_behaviour(fkit, args, counter, temp);
	else if (fkit.type == 'x')
		ft_x_behaviour(fkit, args, counter, temp);
	else if (fkit.type == 'X')
		ft_xx_behaviour(fkit, args, counter, temp);
}
