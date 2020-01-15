/*
** EPITECH PROJECT, 2019
** Malloc
** File description:
** making list
*/

#include "list.h"

void put_in_list(t_mlist **list, size_t size, void *address)
{
    t_mlist *temp = sbrk(sizeof(*temp));

    if (temp == SBRK_FAIL) {
        list = NULL;
        return ;
    }
    temp->size = size;
    temp->_isuse = USE;
    temp->address = address;
    if (!*list)
        temp->head = 1;
    else {
        temp->head = 0;
        temp->next = *list;
    }
    *list = temp;
    make_circle_list(list);
}

void make_circle_list(t_mlist **list)
{
    t_mlist *temp;

    temp = *list;
    while ((*list)->head != 1)
        (*list) = (*list)->next;
    (*list)->next = temp;
    while ((*list) != temp)
        *list = (*list)->next;
}


void init_list(void)
{
    while (list_global->head != 1)
        list_global = list_global->next;
    list_global = list_global->next;
}

int check_list(void *ptr)
{
    t_mlist *temp;

    temp = list_global;
    while (temp->address != ptr && temp->head != 1)
        temp = temp->next;
    if (temp->address != ptr)
        return (FALSE);
    return (TRUE);
}

size_t get_lenght(void *ptr)
{
    t_mlist *temp;

    temp = list_global;
    while (temp->address != ptr)
        temp = temp->next;
    return (temp->size);
}
