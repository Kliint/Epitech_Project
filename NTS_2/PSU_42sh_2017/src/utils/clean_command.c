/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** clean_command
*/

#include "shell.h"

char    *clean_command(char *str)
{
	int   i = 0;
	int   counter = 0;
	int   size;
	char  *cleaned_str;

	if (str == NULL || str == 0)
		return (NULL);
	if (str[0] == '.')
		counter++;
	if (str[1] == '/')
		counter++;
	if (counter == 2) {
		if ((size = strlen(str) > 2)) {
			i = size - 2;
			size = 0;
			if ((cleaned_str = malloc(sizeof(char) * i + 1)) == NULL)
				return (NULL);
			else
				while (str[counter] != '\0') {
					cleaned_str[size] = str[counter];
					size++;
					counter++;
				}
		}
		return (cleaned_str);
	}
	return (str);
}

