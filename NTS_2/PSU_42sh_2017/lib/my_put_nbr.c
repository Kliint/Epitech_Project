/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** print int
*/

#include "my.h"

void	my_put_nbr(int nb)
{
	if (nb < 0){
		nb = nb * -1;
		my_putchar('-');
		my_put_nbr(nb);
	} else if (nb >= 0 && nb < 10)
		my_putchar(nb + '0');
	else {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	}
}
