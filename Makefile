LIBFT = ./libft/libft.a

NAME 			= libftprintf.a

DIR_S			= src

SOURCE			= ft_printf.c ft_putchar.c ft_tdef_init.c \
				ft_validation.c ft_flags.c ft_type.c \
				ft_char_behaviour.c ft_string_behaviour.c \
				ft_pointer_behaviour.c ft_putstr.c ft_digit_behaviour.c \
				ft_digit_behaviour2.c ft_itoa_u.c ft_unsignedint_behaviour.c \
				ft_x_behaviour.c ft_itoa_ux.c ft_xx_behaviour.c \
				ft_itoa_uxx.c ft_perc_behaviour.c

SRCS			= $(addprefix $(DIR_S)/,$(SOURCE))
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
INCLUDES		= -I./includes

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a ./$(NAME)		
				ar -rcs $(NAME) $(OBJS)
			
				@printf "$(_GREEN)\t\t✓✓✓ SUCCESSFUL COMPILATION! ✓✓✓$(_GREEN)\n"

test:			all
				@printf "$(_GREEN)Compiling test file main.c\n"
				@printf "$(_GREEN)"
				@printf "$(_CYAN) ══════════════════════════════$(_END) \n"
				gcc main.c $(NAME) && ./a.out
				@printf "\n$(_CYAN) ══════════════════════════════ $(_END) \n"
clean:
				$(MAKE) clean -C./libft	
				$(RM) $(OBJS)		

fclean:			clean
				$(MAKE) fclean -C./libft
				$(RM) $(NAME)
				

re:				fclean all


smile:
	@clear
	@echo 		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░░█▄
	@echo		\	\	\	\					░▄▄▄▄▄▄░░░░░░░░░░░░░▄▄▄▄▄░░█▄
	@echo		\	\	\	\					░▀▀▀▀▀███▄░░░░░░░▄███▀▀▀▀░░░█▄
	@echo		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	@echo		\	\	\	\					░▄▀▀▀▀▀▄░░░░░░░░░░▄▀▀▀▀▀▄░░░░█
	@echo		\	\	\	\					█▄████▄░▀▄░░░░░░▄█░▄████▄▀▄░░█▄
	@echo		\	\	\	\					████▀▀██░▀▄░░░░▄▀▄██▀█▄▄█░█▄░░█				
	@echo		\	\	\	\					██▀██████░█░░░░█░████▀█▀██░█░░█
	@echo		\	\	\	\					████▀▄▀█▀░█░░░░█░█████▄██▀▄▀░░█
	@echo		\	\	\	\					███████▀░█░░░░░░█░█████▀░▄▀░░░█
	@echo		\	\	\	\					░▀▄▄▄▄▄▀▀░░░░░░░░▀▀▄▄▄▄▀▀░░░░░█
	@echo		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	@echo		\	\	\	\					░░▓▓▓▓▓▓▓░░░░░░░░░░▓▓▓▓▓▓▓░░░░█
	@echo		\	\	\	\					░░░▓▓▓▓▓░░░░░░░░░░░░▓▓▓▓▓░░░░░█
	@echo		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	@echo		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█▀
	@echo		\	\	\	\					░░░░░░░░░▄▄███████▄▄░░░░░░░░░█
	@echo		\	\	\	\					░░░░░░░░█████████████░░░░░░░█▀
	@echo		\	\	\	\					░░░░░░░░░▀█████████▀░░░░░░░█▀
	@echo		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░░█▀
	@echo		\	\	\	\					░░░░░░░░░░░░░░░░░░░░░░░░░█▀


	

.PHONY:			all clean fclean re smile