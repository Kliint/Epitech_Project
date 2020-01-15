/*
1;4804;0c** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** print non printable with octo base
*/

#include "my.h"

void	put_octal_car(char c)
{
	if (c < 8) {
		my_putchar('0');
		my_putchar('0');
		my_putnbr_base(c, "01234567");
	}
	else if (c < 64) {
		my_putchar('0');
		my_putnbr_base(c, "01234567");
	}
	else {
		my_putnbr_base(c, "01234567");
	}
}


void	my_putstr_noprintable(char *str)
{
	int	i = 0;

	while(str[i] != '\0') {
		if (str[i] < 32 || str[i] == 127) {
			my_putchar('\\');
			put_octal_car(str[i]);
		}
		else
			my_putchar(str[i]);
		i = i + 1;
	}

}
