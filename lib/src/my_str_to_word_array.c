/*
** EPITECH PROJECT, 2024
** Phoenix_Day4
** File description:
** split_string
*/

#include "../include/my.h"

int count_words(char const *str)
{
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        if (my_isalnum(str[a]) == 1 && my_isalnum(str[a + 1]) != 1) {
            b++;
        }
        a++;
    }
    return b;
}

int len_of_word(char *str, int i)
{
    while (str[i] != '\0') {
        if (my_isalnum(str[i]) != 1) {
            return i;
        }
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int words_total = count_words(str);
    char **array = malloc(sizeof(char *) * (words_total + 1));
    int a = 0;
    int b = 0;
    int c = 0;

    while (b < words_total) {
        array[b] = malloc(sizeof(char) * (len_of_word((char *)str, a) + 1));
        c = 0;
        while (str[a] != '\0' && my_isalnum(str[a]) == 1) {
            array[b][c] = str[a];
            c++;
            a++;
        }
        array[b][c] = '\0';
        a++;
        b++;
    }
    array[b] = NULL;
    return array;
}
