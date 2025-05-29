/*
** EPITECH PROJECT, 2024
** Phoenix_Day4
** File description:
** my_isalpha
*/

#include "../include/my.h"

int my_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}
