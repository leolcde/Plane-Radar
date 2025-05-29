/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_char
*/

#include "../include/my.h"

int my_put_char(int c)
{
    write(1, &c, 1);
}
