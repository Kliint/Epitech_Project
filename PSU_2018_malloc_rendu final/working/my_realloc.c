/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** realloc function
*/

#include "list.h"

//extern t_mlist *list_global;

void *realloc(void *ptr, size_t size)
{
    void *cpy;
    size_t ptr_size;

    if (size == 0 && ptr != NULL)
    {
        free(ptr);
        return (ptr);
    }
    else if (ptr == NULL || check_list(ptr) == 1)
        ptr = malloc(size);
    else {
        ptr_size = find_lenght(ptr);
        if (ptr_size == size)
            return (ptr);
        else
            memcpy(cpy, ptr, ptr_size);
        free(ptr);
        return (cpy);
    }
    return (ptr);
}


