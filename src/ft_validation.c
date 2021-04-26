#include "../includes/ft_printf.h"

int	type_check(char work_char)
{
	if (work_char == 'c' || work_char == 's' || work_char == 'p'
		|| work_char == 'd' || work_char == 'i' || work_char == 'u'
		|| work_char == 'x' || work_char == 'X' || work_char == '%')
		return (1);
	return (0);
}
