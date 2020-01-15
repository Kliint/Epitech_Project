##
## EPITECH PROJECT, 2017
## MY_PRINTF
## File description:
## Makefile of my_printf
##

AR	=	ar rc

RM	=	rm -f

CFLAGS	+= -Wall -Wextra -Werror -I./../include  

NAME	=	libmy.a

SRCS	=	./get_next_line.c\

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
