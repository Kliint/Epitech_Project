/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** printf_ functions
*/
#include "my.h"
#include "my_printf.h"

void	my_printf_d(va_list ap)
{
	my_put_nbr(va_arg(ap,int));
}

void	my_printf_s(va_list ap)
{
	my_putstr(va_arg(ap, char *));
}

void	my_printf_c(va_list ap)
{
	my_putchar(va_arg(ap,int));
}

void	my_printf_x(va_list ap)
{
	my_putnbr_base_hex_x(va_arg(ap,int));
}

void	my_printf_o(va_list ap)
{
	my_putnbr_base_octo(va_arg(ap,int));
}
