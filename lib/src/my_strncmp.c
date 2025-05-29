/*
** EPITECH PROJECT, 2024
** Phoenix_Day2
** File description:
** my_strncmp
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0) {
        return 0;
    }
    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    if (i < n) {
        return s1[i] - s2[i];
    }
    return 0;
}
