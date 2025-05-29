/*
** EPITECH PROJECT, 2024
** Organized
** File description:
** my_isnumber
*/

#include "../include/my.h"

int my_isnumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        return str[i] >= '0' && str[i] <= '9';
}
