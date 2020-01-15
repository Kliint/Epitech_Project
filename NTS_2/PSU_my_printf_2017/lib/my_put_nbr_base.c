/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** put_nbr with base
*/

#include "my.h"

void	unit_base_print(long int nb, char *base)
{
	while (nb > 0) {
		my_putchar(base[0]);
		nb = nb - 1;
	}
}

void    my_putnbr_base(long int  nb, char *base)
{
  unsigned long int	base_len = my_strlen(base);;
  unsigned long int	i = 1;
  unsigned long int	base_index;

  if (base_len == 1) {
	  unit_base_print(nb, base);
	  return ;
    }
  while (i <= nb/base_len)
    i = i * base_len;
  while (i > 0) {
      base_index = nb / i % base_len;
      my_putchar(base[base_index]);
      i = i / base_len;
    }
}

void	my_putnbr_base_hex_X(int nb)
{
	my_putnbr_base((long int)nb, "0123456789ABCDEF");
}

void	my_putnbr_base_octo(int nb)
{
	my_putnbr_base((long int)nb, "01234567");
}

void	my_putnbr_base_bin(int nb)
{
	my_putnbr_base((long int)nb, "01");
}
