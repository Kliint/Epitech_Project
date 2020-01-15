/*
** EPITECH PROJECT, 2019
** malloc 
** File description:
** free function 
*/

#include "alloc.h"

void free(void *ptr)
{
    if (ptr == NULL && check_list(ptr) == FALSE)
        return ;
    while (ptr != list_global->adress && list_global->head != 1)
        list_global = list_global->next;
    if (!list_global->_isuse)
        return ;
    list_global->_isuse = NOTUSE;
    if (list_global->head != 1) {
        if (list_global->next->_isuse == NOTUSE &&
            list_global->next->adress != list_global->adress) {
            if (list_global->adress > list_global->next->adress)
                list_global->adress = list_global->next->adress;
            list_global->head = list_global->next->head;
            list_global->size += list_global->next->size;
            list_global->next = list_global->next->next;
        }
    }
    init_list();
}
