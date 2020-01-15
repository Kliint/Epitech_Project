/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** printf_function bis
*/
#include "my.h"
#include "my_printf.h"

void	my_printf_u(va_list ap)
{
	my_putnbr_base_unsigned(va_arg(ap,int));
}

void	my_printf_S(va_list ap)
{
	my_putstr_noprintable(va_arg(ap,char *));
}

void	my_printf_b(va_list ap)
{
	my_putnbr_base_bin(va_arg(ap,int));
}

void	my_printf_X(va_list ap)
{
	my_putnbr_base_hex_X(va_arg(ap,int));
}

void	my_printf_p(va_list ap)
{
	my_putstr("0x");
	my_putnbr_base_hex_x(va_arg(ap, int));
}
