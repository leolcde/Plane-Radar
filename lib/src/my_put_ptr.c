/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_ptr
*/

#include "../include/my.h"

int my_put_ptr(char *str)
{
    char *nbr = str;
    long stk = 0;
    long i = 1;
    long j = 0;
    char hex[100];

    while (nbr != 0) {
        stk = *nbr % 16;
        if (stk < 10)
            stk += 48;
        else
            stk += 87;
        hex[i] = stk;
        i++;
        *nbr /= 16;
    }
    my_put_ptr("0x");
    for (j = i -1; j > 0; j--) {
        my_put_char(hex[j]);
    }
}
