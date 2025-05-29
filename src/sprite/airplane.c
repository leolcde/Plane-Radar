/*
** EPITECH PROJECT, 2025
** projet_radar
** File description:
** airplane
*/

#include "../../includes/my.h"

void *init_airplane(airplane_t *plane)
{
    sfVector2u texture_size;

    plane->texture = sfTexture_createFromFile("content/plane.png", NULL);
    if (plane->texture == NULL) {
        return NULL;
    }
    plane->sprite = sfSprite_create();
    if (plane->sprite == NULL) {
        sfTexture_destroy(plane->texture);
        return NULL;
    }
    sfSprite_setTexture(plane->sprite, plane->texture, sfTrue);
    texture_size = sfTexture_getSize(plane->texture);
    sfSprite_setOrigin(plane->sprite,
        (sfVector2f){texture_size.x / 2.0f, texture_size.y / 2.0f});
    sfSprite_setPosition(plane->sprite,
        (sfVector2f){plane->start.x, plane->start.y});
    sfSprite_setScale(plane->sprite, (sfVector2f){0.1, 0.1});
    return plane;
}

void display_hitbox(sfRenderWindow *window, sfSprite *sprite,
    airplane_t *plane, hitbox_t *must_display)
{
    sfVector2f position = sfSprite_getPosition(sprite);
    sfVector2f scale = sfSprite_getScale(sprite);
    sfTexture *texture = (sfTexture *)sfSprite_getTexture(sprite);
    sfVector2u texture_size = sfTexture_getSize(texture);
    sfVector2f size = {texture_size.x * scale.x, texture_size.y * scale.y};
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f origin_correction = {size.x / 2.0f, size.y / 2.0f};

    sfRectangleShape_setPosition(hitbox,
        (sfVector2f){position.x - origin_correction.x,
        position.y - origin_correction.y});
    sfRectangleShape_setSize(hitbox, size);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 2.0);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    if (must_display->display_airplanes_hitbox == 1)
        sfRenderWindow_drawRectangleShape(window, hitbox, NULL);
    sfRectangleShape_destroy(hitbox);
}

void update_airplane_position(airplane_t *plane, float elapsed_time,
    float total_elapsed_time)
{
    float effective_time = elapsed_time - plane->delay;
    float total_distance_x = plane->end.x - plane->start.x;
    float total_distance_y = plane->end.y - plane->start.y;
    float total_distance = sqrtf(total_distance_x * total_distance_x +
        total_distance_y * total_distance_y);
    float direction_x = total_distance_x / total_distance;
    float direction_y = total_distance_y / total_distance;
    float move_x = direction_x * plane->speed * elapsed_time;
    float move_y = direction_y * plane->speed * elapsed_time;

    if (total_elapsed_time < plane->delay || total_distance == 0) {
        return;
    }
    sfSprite_move(plane->sprite, (sfVector2f){move_x, move_y});
}

void update_airplanes(airplane_t *plane_list,
    float elapsed_time, float total_elapsed_time)
{
    airplane_t *current = plane_list;

    while (current != NULL) {
        update_airplane_position(current, elapsed_time, total_elapsed_time);
        current = current->next;
    }
}

void display_airplanes(sfRenderWindow *window, airplane_t *plane,
    hitbox_t *must_display)
{
    while (plane != NULL) {
        sfRenderWindow_drawSprite(window, plane->sprite, NULL);
        display_hitbox(window, plane->sprite, plane, must_display);
        plane = plane->next;
    }
}
