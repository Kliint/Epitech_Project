/*
1;4804;0c1;4804;0c** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** my_printf fucntion
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"


static struct identifier FLAGS[] =
{
	{'o', &my_printf_o},
	{'d', &my_printf_d},
	{'i', &my_printf_d},
	{'x', &my_printf_x},
	{'X', &my_printf_X},
	{'c', &my_printf_c},
	{'u', &my_printf_u},
	{'S', &my_printf_S},
	{'b', &my_printf_b},
	{'s', &my_printf_s},
	{'p', &my_printf_p},
	{'%', &my_printf_mod},
	{'\0', 0}
};

int	do_flag(char letter, va_list ap)
{
	int	i = 0;
	
	while (FLAGS[i].flag != '\0') {
		if (FLAGS[i].flag == letter) {
			FLAGS[i].func(ap);
			return (1);
		}
		i += 1;
	}
	return (0);
}

void		check_case(char flag, va_list ap)
{
	if (do_flag(flag, ap) == 0) {
		my_putchar('%');
		my_putchar(flag);
	}
		
}

void		my_printf(char const *str, ...)
{
	va_list	ap;
	int	i = 0;
 
	va_start(ap, str);
	while (str[i]) {
		if (str[i] == '%') {
			i = i + 1;
			check_case(str[i],ap);
			i += 1;
		}
		else if (str[i] != '%'){
			my_putchar(str[i]);
			i += 1;
		}
	}
}
