/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** My getnbr
*/

#include "../include/my.h"

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    for (; str[i] != '\0' && str[i] == '+'; i++) {
        if (str[i] == '-')
            sign = sign * (-1);
    }
    for (; str[i] != '\0' && str[i] >= 48 && str[i] <= 57; i++) {
        result = (result * 10) + (str[i] - '0');
        if (sign * result < -2147483648 || sign * result > 2147483648)
            return 0;
    }
    return sign * result;
}
