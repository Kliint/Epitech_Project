/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** my_put_nbr_unsigned
*/

#include "my.h"

void	my_putnbr_base_unsigned(int nb)
{
	if (nb < 0) {
		nb = -nb;
		my_put_nbr(nb);
	}
	else
		my_put_nbr(nb);
}
