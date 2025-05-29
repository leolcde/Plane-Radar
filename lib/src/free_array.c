/*
** EPITECH PROJECT, 2024
** Library
** File description:
** free_array
*/

#include "../include/my.h"

void free_word_array(char **word_array, int word_count)
{
    for (int i = 0; i < word_count; i++) {
        free(word_array[i]);
    }
    free(word_array);
}
