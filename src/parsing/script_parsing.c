/*
** EPITECH PROJECT, 2025
** my_radarfinal
** File description:
** script_parsing
*/

#include "../includes/my.h"
#include "../lib/include/my.h"

void parse_line(char *line, airplane_t **head_a, tower_t **head_tow)
{
    char **parsing_array = my_str_to_word_array(line);
    static int i = 0;

    if (line == NULL) {
        return;
    }
    if (parsing_array == NULL) {
        return;
    }
    if (parsing_array[0][0] == 'A') {
        parse_airplane(parsing_array, head_a);
        i++;
    } else if (parsing_array[0][0] == 'T') {
        parse_tower(parsing_array, head_tow);
        i++;
    }
    for (int i = 0; parsing_array[i] != NULL; i++) {
        free(parsing_array[i]);
    }
    free(parsing_array);
}

static FILE *open_file_safe(const char *script_path)
{
    if (script_path == NULL) {
        return NULL;
    }
    return fopen(script_path, "r");
}

int script_parsing(const char *script_path,
    airplane_t **head_a, tower_t **head_tow)
{
    FILE *script;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    script = open_file_safe(script_path);
    if (script == NULL)
        return 84;
    while (1) {
        read = getline(&line, &len, script);
        if (read == -1)
            break;
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';
        parse_line(line, head_a, head_tow);
    }
    free(line);
    fclose(script);
    return 0;
}
