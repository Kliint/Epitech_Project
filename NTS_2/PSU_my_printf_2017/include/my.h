/*
** EPITECH PROJECT, 2017
** MY_PRINTF
** File description:
** header of lib for my_printf
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>

void	my_putstr_noprintable(char *);
void	my_putstr(char *);
void	my_putchar(char);
void	unit_base_print(long int, char *);
void	my_putnbr_base(long int, char *);
void	my_putnbr_base_hex_X(int);
void	my_putnbr_base_hex_x(int);
void	my_putnbr_base_octo(int);
void	my_putnbr_base_bin(int);
void	my_put_nbr(int);
int	my_strlen(char *);
void	my_putnbr_base_unsigned(int);	

#endif /* ! MY_H_ */
