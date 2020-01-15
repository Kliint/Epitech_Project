/*
** EPITECH PROJECT, 2017
** my_printf_h
** File description:
** header file for printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
        char zero;
        char sign1;
        char sign2;
        char *nb1;
        char *nb2;
	int pointer;
        int lasti;
        int error;
} printf_attribs;
int my_putnbr(va_list ap, printf_attribs);
void my_put_attribs(printf_attribs attribs, int nb);
int get_int_size(int nb);
int my_put_binary(va_list ap, printf_attribs);
int my_put_hexa(va_list ap, printf_attribs);
int my_put_hexa_up(va_list ap, printf_attribs);
long power_it_long(long nb ,long power);
int my_put_spaces_after(printf_attribs , long, long);
int my_put_str_args(va_list ap, printf_attribs);
int write_blank_space(printf_attribs , long , int);
int write_blank_space_double(printf_attribs , long , int );
int write_zero_single(printf_attribs attribs,long place,long nb);
int my_put_str_spaces(int , int );
int prepare_pointer_attribs(printf_attribs attribs);
int my_put_nbr_attribs(int basesize, long , printf_attribs , long);
int my_put_double_attribs(printf_attribs , long, long);
int my_put_long(va_list ap, printf_attribs);
int do_put_long(long place, char *base, long nb, printf_attribs attribs);
int my_putlong_base(long nb, char *base, printf_attribs attribs);
int power_it(int nb ,int power);
int do_put_nbr(int place, int basesize, char const *base, int nb);
int my_put_hexa_point(va_list ap, printf_attribs);
int my_put_modulo(va_list ap, printf_attribs);
int my_put_octal(va_list ap, printf_attribs);
int my_put_unsigned(va_list ap, printf_attribs);
int my_printf(char *str, ...);
int my_put_str(char *str);
int get_str_nb_size(char *str, int i);
int my_getnbr(char const *str, int i);
int get_sizebase(char const *base);
int my_putnbr_short(short nb, char const *base);
int my_put_unsigned_base(unsigned int nb, char const *base);
int my_put_str_formated(va_list ap, printf_attribs attribs);
int my_putchar(va_list ap, printf_attribs attribs); 
int my_putnbr_base(int nb, char const *base);
int my_strlen(char *str);
void my_put_error(char *str);
int compare_c_from_str(char c, char str_offset);
char *my_str_alloc(char *str);
int my_put_attribs_str(char *str, printf_attribs attribs);
typedef int (*function_table)(va_list ap,printf_attribs attribs);
typedef struct {
	char function_name;
	function_table table;
} simple_printf_flag;
printf_attribs get_attribs(char *str, int i, printf_attribs atribs);
int is_function(char c);
printf_attribs set_attribs_zero(printf_attribs attribs);
function_table get_function(char c);
#endif /* MY_PRINTF_H_ */
