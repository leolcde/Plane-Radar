/*
** EPITECH PROJECT, 2025
** my_radarfinal
** File description:
** plane_parsing
*/

#include "../../includes/my.h"
#include "../../lib/include/my.h"

void parse_airplane(char **parsing_array, airplane_t **airplane_list)
{
    airplane_t *new_node = malloc(sizeof(airplane_t));

    if (parsing_array == NULL) {
        return;
    }
    new_node->start = (sfVector2i){
        my_str_to_int(parsing_array[1]),
        my_str_to_int(parsing_array[2])
    };
    new_node->end = (sfVector2i){
        my_str_to_int(parsing_array[3]),
        my_str_to_int(parsing_array[4])
    };
    new_node->speed = my_str_to_int(parsing_array[5]);
    new_node->delay = my_str_to_int(parsing_array[6]);
    init_airplane(new_node);
    new_node->next = *airplane_list;
    *airplane_list = new_node;
}
