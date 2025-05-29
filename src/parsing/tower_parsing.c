/*
** EPITECH PROJECT, 2025
** my_radarfinal
** File description:
** tower_parsing
*/

#include "../../includes/my.h"
#include "../../lib/include/my.h"

void parse_tower(char **parsing_array, tower_t **tower_list)
{
    tower_t *new_node = malloc(sizeof(tower_t));

    if (parsing_array == NULL) {
        return;
    }
    new_node->position = (sfVector2i){
        my_str_to_int(parsing_array[1]),
        my_str_to_int(parsing_array[2])
    };
    new_node->radius = my_str_to_int(parsing_array[3]);
    init_tower(new_node);
    new_node->next = *tower_list;
    *tower_list = new_node;
}
