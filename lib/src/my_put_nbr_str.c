/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_nbr_str
*/

#include "../include/my.h"

int my_put_nbr_str(char *str)
{
    int i = 0;
    int res;

    for (i; str[i] != '%'; i++);
    my_put_nbr(i);
    return 0;
}
