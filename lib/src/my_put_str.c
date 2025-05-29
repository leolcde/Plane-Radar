/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_put_str(char const *str)
{
    while (*str != '\0') {
        my_put_char(*str);
        str++;
    }
}
