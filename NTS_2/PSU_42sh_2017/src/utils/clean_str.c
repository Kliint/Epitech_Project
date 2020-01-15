/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** clean_str
*/

#include "shell.h"

int     check_equal(char *str)
{
	int   i = 0;
  
	while (str[i] != '\0') {
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char    *clean_str(char *str)
{
	int   i = 0;
	int   counter = 0;
	char  *cleaned_str;
	int   diff;

	if ((check_equal(str)) == 0)
		return (str);
	while (str[i] != '=')
		i++;
	counter = i + 1;
	if ((i = strlen(str)) == 0)
		return (NULL);
	diff = i - counter;
	if ((cleaned_str = malloc(sizeof(char) * diff)) == NULL)
		return (NULL);
	i = 0;
	while (str[counter]) {
		cleaned_str[i++] = str[counter++];
	}
	cleaned_str[i] = '\0';
	return (cleaned_str);
}

