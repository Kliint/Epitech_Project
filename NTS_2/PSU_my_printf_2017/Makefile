##
## EPITECH PROJECT, 2017
## MY_PRINTF
## File description:
## Makefile of my_printf
##

AR	=	ar rc

RM	=	rm -f

CFLAGS	+= -Wall -Wextra -Werror -I./include -L./lib -lmy 

NAME	=	libmy.a

SRCS	=	./printf_id_func/printf_func.c\
		./printf_id_func/printf_func_bis.c\
		./printf_id_func/printf_func_ter.c\
		./src/my_printf.c\
		./lib/my_putchar.c\
		./lib/my_put_nbr_base.c\
		./lib/my_put_nbr_unsigned.c\
		./lib/my_putnbr_base_x.c\
		./lib/my_putstr.c\
		./lib/my_putstr_noprintable.c\
		./lib/my_strlen.c\
		./lib/my_put_nbr.c\

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS)
	find -name "*~" -delete
	find -name "#*#" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
