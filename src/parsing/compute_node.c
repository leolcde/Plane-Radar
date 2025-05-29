/*
** EPITECH PROJECT, 2025
** my_radarfinal
** File description:
** compute_node
*/

#include "../../includes/my.h"

int compute_node(airplane_t *plane)
{
    int count = 0;

    while (plane != NULL) {
        count++;
        plane = plane->next;
    }
    return count;
}
