/*
** EPITECH PROJECT, 2024
** Phoenix
** File description:
** reverse_string
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    char *start = str;
    char *end = str + my_strlen(str) - 1;
    char tmp;

    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return str;
}
