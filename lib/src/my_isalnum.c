/*
** EPITECH PROJECT, 2024
** Phoenix_Day4
** File description:
** my_isalnum
*/

#include "../include/my.h"

int my_isalnum(int c)
{
    if ((my_isdigit(c) == 1) || (my_isalpha(c) == 1))
        return (1);
    else
        return (0);
}
