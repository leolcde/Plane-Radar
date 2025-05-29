/*
** EPITECH PROJECT, 2024
** Phoenix_Day2
** File description:
** my_strstr
*/

#include "../include/my.h"

char *my_strstr(char *str, const char *to_find)
{
    int j;

    if (*to_find == '\0')
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        for (j = 0; to_find[j] != '\0' && str[i + j] == to_find[j]; j++);
        if (to_find[j] == '\0')
            return &str[i];
    }
    return NULL;
}
