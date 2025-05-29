/*
** EPITECH PROJECT, 2024
** Ls
** File description:
** my_str_cmp
*/

#include "../include/my.h"

int my_str_cmp(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return (0);
    }
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
