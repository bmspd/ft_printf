#include "../includes/ft_printf.h"

static void	ft_zmin_width(char *work_str, va_list args, int *i, t_flags *fkit)
{
	if (work_str[*i] == '0' && fkit->width == 0 && fkit->f_minus == 0)
	{
		fkit->f_zero = 1;
		(*i)++;
	}
	if (work_str[*i] == '-')
		*fkit = ft_flag_minus(*fkit);
	if (work_str[*i] == '*')
		*fkit = ft_flag_argwidth(*fkit, args, i);
	if (ft_isdigit(work_str[*i]))
		*fkit = ft_flag_width(*fkit, work_str, i);
	if (work_str[*i] == '.')
	{
		(*i)++;
		fkit->accuracy = 0;
	}
}

int	ft_flag_parsing(char *work_str, va_list args, int i, t_flags *fkit)
{
	i++;
	while (work_str[i])
	{
		if (!(ft_validation(work_str[i])))
			break ;
		ft_zmin_width(work_str, args, &i, fkit);
		if (work_str[i] == '*')
			*fkit = ft_flag_argaccuracy(*fkit, args, &i);
		if (ft_isdigit(work_str[i]))
			*fkit = ft_flag_accuracy(*fkit, work_str, &i);
		if (type_check(work_str[i]))
		{
			*fkit = ft_type(*fkit, work_str[i]);
			break ;
		}
		i++;
	}
	return (i);
}

int	countingnprinting(char *work_str, va_list args, int *counter)
{
	int		i;
	t_flags	fkit;

	i = 0;
	while (work_str[i] != '\0')
	{
		if (work_str[i] != '%')
		{
			ft_putchar(work_str[i]);
			(*counter)++;
		}
		if (work_str[i] == '%')
		{
			fkit = ft_tdef_init(fkit);
			i = ft_flag_parsing(work_str, args, i, &fkit);
			ft_choosingtype(fkit, args, counter);
		}
		i++;
	}
	return (*counter);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	char	*work_str;
	int		counter;

	counter = 0;
	work_str = ft_strdup(string);
	va_start(args, string);
	counter = countingnprinting(work_str, args, &counter);
	free(work_str);
	va_end(args);
	return (counter);
}
