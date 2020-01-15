/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** header for printf
*/

#ifndef	MY_PRINTF_H_
# define	MY_PRINTF_H_

#include <stdarg.h>

struct	identifier
{
	char	flag;
	void	(*func)(va_list);
};

void	my_printf_c(va_list);
void	my_printf_d(va_list);
void	my_printf_u(va_list);
void	my_printf_b(va_list);
void	my_printf_d(va_list);
void	my_printf_S(va_list);
void	my_printf_X(va_list);
void	my_printf_x(va_list);
void	my_printf_s(va_list);
void	my_printf_u(va_list);
void	my_printf_o(va_list);
void	my_printf_p(va_list);
void	my_printf_mod(va_list);
int	count_flags(char const *);
char	*find_flags(char const *);
void	my_printf(char const *, ...);
int	do_flag(char, va_list);
void	check_case(char, va_list);
#endif /* ! MY_PRINTF_H_*/
