/*
** EPITECH PROJECT, 2017
** function_map
** File description:
** function map header file
*/

#include "my_printf.h"

simple_printf_flag simple_function_map[14] = {
        {'d', my_putnbr},
	{'b', my_put_binary},
        {'x', my_put_hexa},
        {'X', my_put_hexa_up},
        {'s', my_put_str_args},
	{'c', my_putchar},
	{'%', my_put_modulo},
	{'i', my_putnbr},
	{'o', my_put_octal},
	{'S', my_put_str_formated},
	{'l', my_put_long},
	{'p', my_put_hexa_point},
	{'u', my_put_unsigned}
};
