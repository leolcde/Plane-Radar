/*
** EPITECH PROJECT, 2024
** Organized
** File description:
** my_linkedlist_len
*/

#include "../include/my.h"

int linkedlist_len(my_linkedlist_t *list)
{
    int counter = 0;

    while (list != NULL) {
        counter++;
        list = list->next;
    }
    return counter;
}
