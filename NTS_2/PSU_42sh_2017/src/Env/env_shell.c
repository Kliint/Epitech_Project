/*
** EPITECH PROJECT, 2018
** MINISHELL
** File description:
** env_shell
*/

#include "shell.h"

char    *env_shell(char **environ)
{
  char  *get_env;

  get_env = NULL;
  get_env = my_env(environ, "PATH");
  return (get_env);
}
