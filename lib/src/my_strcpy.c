/*
** EPITECH PROJECT, 2024
** Phoenix_Day2
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len;

    if (dest == NULL || src == NULL) {
        return NULL;
    }
    len = my_strlen(src);
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}
