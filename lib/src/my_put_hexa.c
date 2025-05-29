/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_hexa
*/

#include "../include/my.h"

static int case_0(int nbr)
{
    if (nbr == 0) {
        my_put_char('0');
        return 0;
    }
}

int my_put_hexa(int ii)
{
    int nbr = ii;
    int stk = 0;
    int i = 1;
    int j = 0;
    char hex[100];

    case_0(nbr);
    while (nbr != 0) {
        stk = nbr % 16;
        if (stk < 10)
            stk += 48;
        else
            stk += 87;
        hex[i] = stk;
        i++;
        nbr /= 16;
    }
    for (j = i -1; j > 0; j--) {
        my_put_char(hex[j]);
    }
}
