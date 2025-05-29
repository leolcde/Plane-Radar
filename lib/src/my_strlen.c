/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** My strlen
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++);
    return i;
}
