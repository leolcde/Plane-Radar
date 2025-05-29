/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_nbr_oct
*/

#include "../include/my.h"

int my_put_oct(int nb)
{
    int i = 0;

    if (nb >= 8) {
        my_put_nbr(nb / 8);
        i++;
    }
    my_put_char((nb % 8) + 48);
}
