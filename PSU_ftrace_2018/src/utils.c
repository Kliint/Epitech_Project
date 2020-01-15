#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "ftrace.h"

int display_error(int errsav) {
	return (print_err("%s\n", strerror(errsav)), 1);
}

int get_nbr(char *str, long int *nbr) {

	char *tmp;

	if (!str || *str == '\0')
		return (1);
	*nbr = strtol(str, &tmp, 10);
	return ((*nbr == LONG_MIN || *nbr == LONG_MAX || *tmp != '\0') ? 1 : 0);
}

int my_power_rec(int nbr, int power) {
	
	return (power ? (nbr * my_power_rec(nbr, power -1)) : 1);
}
