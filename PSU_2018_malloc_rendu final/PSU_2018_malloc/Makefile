##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Malloc, Free, Realloc
##

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra -fPIC

RM		=	rm -f

SRC		=	src/my_malloc.c \
			src/list.c

OBJ		=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
			gcc -c $(CFLAGS) -fpic $(SRC)
			gcc -shared -o $(NAME) $(OBJ)

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(OBJ)

re		:	fclean all