#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>  // !!!!!!!!!!!!DONT FORGET TO REMOVE!!!!!!!!!!

typedef struct s_flags
{
	int	f_zero;
	int f_minus;
	int	type;
	int width;
	int accuracy;
}	t_flags;


void ft_putchar(char c);
void ft_putstr(char *str);
int	ft_printf(const char *, ...);
t_flags	ft_tdef_init(t_flags flag_kit);
int	ft_flag_parsing(char *work_str, va_list args, int i, t_flags *fkit);
int	ft_validation(char work_char);
int type_check(char work_char);


t_flags ft_flag_minus(t_flags fkit);
t_flags ft_flag_width(t_flags fkit, char *work_str, int *i);
t_flags ft_flag_argwidth(t_flags fkit, va_list args, int *i);
t_flags ft_flag_accuracy(t_flags fkit, char *work_str, int *i);
t_flags ft_flag_argaccuracy(t_flags fkit, va_list args, int *i);
t_flags	ft_type(t_flags fkit, char work_char);

void ft_choosingtype(t_flags fkit, va_list args, int *counter);
void ft_char_behaviour(t_flags fkit, va_list args, int *counter);
void ft_string_behaviour(t_flags fkit, va_list args, int *counter);
void ft_pointer_behaviour(t_flags fkit, va_list args, int *counter);

# endif