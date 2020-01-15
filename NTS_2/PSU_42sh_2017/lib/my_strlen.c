/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** my_strlen for printf project
*/

#include "my.h"

int	my_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i += 1;
	return (i);
}
