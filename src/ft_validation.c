#include "../includes/ft_printf.h"

static int	struct_check(char work_char)
{
	if (work_char == '-' || work_char == '0' || work_char == '.'
		|| work_char == '*')
		return (1);
	return (0);
}

int	type_check(char work_char)
{
	if (work_char == 'c' || work_char == 's' || work_char == 'p'
		|| work_char == 'd' || work_char == 'i' || work_char == 'u'
		|| work_char == 'x' || work_char == 'X' || work_char == '%')
		return (1);
	return (0);
}

int	ft_validation(char work_char)
{
	if (ft_isdigit(work_char) || struct_check(work_char)
		|| type_check(work_char))
		return (1);
	return (0);
}
