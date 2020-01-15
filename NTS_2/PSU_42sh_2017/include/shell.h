/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** header
*/

#ifndef	SHELL_H_
#define	SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "my_printf.h"
struct	types_c
{
	char	*flag;
	void	(*func)(char **, char **);
};

/* strtowordtab */
int	nbr_word(char *);
int	letter(char *);
int	check(char);
char	**epur_tab(char **);
char	**my_str_to_wordtab(char *);

/*utils*/
char	*clean_command(char *);
int	check_equal(char *);
char	*clean_str(char *);
char	*get_next_line(int);
void	putstr(char *);
int	my_strcmp(char *, char *);
/* prompt */
void	prompt_display(char **);
int	prompt(char **);
int	exec_command(char *, char **, char **);
int	execution_simple_command(char * , char **, char **);
int	command_interpreter(char **, char *, char **);
int	basic_command(char **, char **);

/* env_function */
int	path_size(char *);
char	*my_env(char **, char *);
char	**my_path(char *);
char	*env_shell(char **);

/* my_access */
char	*check_function(char **, char *);
char	*check_path(char **);
char	**my_access(char **, char *);

/* echo */
void	echo_cmd_basic(char *, char *);
int	echo_cmd_n(char *, char *);
void	echo(char **, char **);

/* signal */
void	get_sig(int);
int	catch_sgve(int);

/* exit */
void	exit_f(char **, char **);

/*lib_function*/
char	**my_str_to_wordtab(char *);

/*changedir*/
void	cd(char **, char **);
int	change_directory(char *, char *, char *);

#endif /* !SHELL_H_*/
