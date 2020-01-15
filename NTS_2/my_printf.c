/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** a regroupment of printfunctions
*/

#include "include/my_printf.h"

int modulo_manage(char *str, int i, va_list ap)
{
	function_table table;
	char sign = 0;
	printf_attribs attribs;

	if (str[i] == '%') {
		attribs = get_attribs(str, i + 1, attribs);
		if (attribs.error == 1)
			return (i); 
		i = attribs.lasti;
		table = get_function(str[i]);
		if (table != NULL) {
			table(ap, attribs);
			i = i + 1;
		}
	}
	return (i);
}

int my_printf(char *str,  ...)
{
	int i = 0;
	va_list ap;
	function_table tabla;
	int done = 0;
	int backi = 0;

	va_start(ap, str);
	while (str[i] != '\0') {
		i = modulo_manage(str, i, ap);
		if (backi == i) {
			write(1, &str[i], 1);
			i++;
		}
		backi = i;
	}
	va_end(ap);
}
