/*
** EPITECH PROJECT, 2024
** Workshop_linked_list
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; str[i] != '\0'; i++) {
        new[i] = str[i];
    }
    new[i] = '\0';
    return new;
}
