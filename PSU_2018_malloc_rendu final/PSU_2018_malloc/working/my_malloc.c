/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** malloc function
*/

#include "list.h"

t_mlist *list_global;

void *malloc(size_t size)
{
    void *adress;
    size = 0;
    static int i = 0;

    printf("LOL\n");

    if (size == 0)
        return (NULL);
    size = (size + 3) & ~3;
    adress = find_free_block(size);
    if (adress != NULL) {
        init_list();
        return (adress);
    }
    adress = sbrk(size);
    if (adress == SBRK_FAIL)
        return (NULL);
    if (i == 0)
        list_global = NULL;
    put_in_list(&list_global, size, adress);
    ++i;
    return (adress);
}


void *find_free_block(size_t size)
{
    t_mlist *cur = list_global; /* current position in the list */

    do {
        if (!cur->_isuse && size <= cur->size) {
            cur->_isuse = USE;
            return (cur->address);
        }
        cur = cur->next;
    } while (cur != list_global);
    init_list();
    return (NULL);
}
