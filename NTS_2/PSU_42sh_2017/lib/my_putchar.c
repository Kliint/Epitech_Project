/*
** EPITECH PROJECT, 2017
** BISTRO-MATIC
** File description:
** print a character
*/

#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}