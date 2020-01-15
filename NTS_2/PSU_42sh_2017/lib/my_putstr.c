/*
** EPITECH PROJECT, 2017
** BISTRO-MATIC
** File description:
** my_putstr
*/

#include "my.h"

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
