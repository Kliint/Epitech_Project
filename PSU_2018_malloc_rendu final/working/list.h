/*
** EPITECH PROJECT, 2019
** EPITECH
** File description:
** malloc list
*/

#ifndef LIST_H_
#define LIST_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "values.h"

typedef struct s_mlist
{
    size_t size;
    int _isuse;
    void *address;
    int head;
    struct s_mlist *next;
} t_mlist;

extern t_mlist *list_global;

//list function

void    *malloc(size_t size);
int     check_list(void *);
void    init_list();
void    put_in_list(t_mlist **, size_t, void *);
void    make_circle_list(t_mlist **);
size_t  get_lenght(void *);
void    *find_free_block(size_t size);
void    *find_free_block(size_t);

#endif /* ! LIST_H_ */
