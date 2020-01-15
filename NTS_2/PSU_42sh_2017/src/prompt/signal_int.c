/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** Signal working
*/

#include "shell.h"

void	putstr(char *str)
{
	write(2, str, my_strlen(str));
}

void    get_sig(int sig)
{
	if (sig == 2) {
		my_printf("\n");
		my_printf("$>:");
	}
}


int     catch_sgve(int status)
{
	if ((WIFSIGNALED(status)) && (WTERMSIG(status) == 11)) {
		if ((WCOREDUMP(status)))
			putstr("Segmentation fault\n");
		else
			putstr("Segmentation fault\n");
		return (139);
	}
	if ((WIFSIGNALED(status)) && (WTERMSIG(status) == SIGFPE)) {
		if ((WCOREDUMP(status)))
			putstr("Floating exception(core dump)\n");
		else
			putstr("Floating exception\n");
		return (136);
	}
	return (0);
}
