#include "../includes/ft_printf.h"

t_flags	ft_tdef_init(t_flags flag_kit)
{
	flag_kit.f_zero = 0;
	flag_kit.f_minus = 0;
	flag_kit.type = 0;
	flag_kit.width = 0;
	flag_kit.accuracy = -1;
	return (flag_kit);
}
