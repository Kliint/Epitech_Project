/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** echo
*/

#include "shell.h"

void	echo(char **command, char **environ)
{
	(void)environ;
	echo_cmd_basic(command[2], command[1]);
}

void    echo_cmd_basic(char *str, char *flag)
{
	int   size;

	if (flag != NULL && flag != 0)
	{
		size = strlen(flag);
		if ((echo_cmd_n(str, flag)) == 0)
			return ;
		else if (str == NULL)
			if (((write(1, flag, size)) != size))
				return;
	}
	my_printf("%c", '\n');
}

int     echo_cmd_n(char *str, char *flag)
{
	int   i = 0;

	if ((my_strncmp(flag, "-n", 2)) != 0)
		return (-1);
	else
	{
		if (str != NULL && str != 0)
			while (str[i] != '\n' && str[i] != '\0')
			{
				my_printf("%c", str[i]);
				i += 1;
			}
	}
	return (0);
}
