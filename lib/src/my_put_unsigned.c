/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_unsigned
*/

#include "../include/my.h"

int my_put_unsigned(int i)
{
    long maxunsigned = 4294967295;
    long res = 0;

    if (i > 0) {
        my_put_long(i);
    } else if (i < 0) {
        res = maxunsigned + i + 1;
        my_put_long(res);
    }
}
