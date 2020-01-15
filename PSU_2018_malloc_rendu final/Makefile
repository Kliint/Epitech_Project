##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Malloc, Free, Realloc
##

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra -fPIC

INCLUDE	+=	-I./working

RM		=	rm -f

SRC		=	./src/my_malloc.c\
			./src/list.c

$(NAME)	:	$(OBJ)
			gcc -c $(CFLAGS) $(INCLUDE) -fpic $(SRC)
			gcc -shared *.o -o $(NAME)

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
