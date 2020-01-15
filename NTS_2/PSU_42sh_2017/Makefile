##
## EPITECH PROJECT, 2018
## MINISHELL1
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Werror -Wextra -I./include -g3 -L./lib -lmy

NAME	=	42sh

SRCS	=	./src/Env/env_function.c\
		./src/Env/env_shell.c\
		./src/prompt/command_interpret.c\
		./src/prompt/execution_command.c\
		./src/prompt/my_access.c\
		./src/prompt/prompt.c\
		./src/prompt/signal_int.c\
		./src/utils/clean_command.c\
		./src/utils/clean_str.c\
		./src/builtin/echo.c\
		./src/builtin/exit_f.c\
		./get_next_line.c\
		./src/utils/my_strncmp.c\
		./main.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C lib
	make clean -C lib
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	find -name "*~" -delete
	find -name "#*#" -delete
	find -name "vgcore.*" -delete
	find -name "'#*#'" -delete

fclean:	clean
	make fclean -C lib
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
