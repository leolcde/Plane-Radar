/*
** EPITECH PROJECT, 2025
** projet_radar
** File description:
** tower
*/

#include "../../includes/my.h"

void *init_tower(tower_t *tower)
{
    sfVector2u texture_size;

    tower->texture = sfTexture_createFromFile("content/tower.png", NULL);
    if (!tower->texture) {
        return NULL;
    }
    tower->sprite = sfSprite_create();
    if (!tower->sprite) {
        sfTexture_destroy(tower->texture);
        return NULL;
    }
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    texture_size = sfTexture_getSize(tower->texture);
    sfSprite_setOrigin(tower->sprite, (sfVector2f){texture_size.x / 2.0f,
        texture_size.y / 2.0f});
    sfSprite_setPosition(tower->sprite, (sfVector2f){tower->position.x,
        tower->position.y});
    sfSprite_setScale(tower->sprite, (sfVector2f){0.17, 0.17});
    return tower;
}

void display_tower_hitbox(sfRenderWindow *window, tower_t *tower,
    hitbox_t *must_display)
{
    sfCircleShape *hitbox;
    int enlarged_radius = tower->radius * 10;

    hitbox = sfCircleShape_create();
    if (!hitbox)
        return;
    sfCircleShape_setRadius(hitbox, enlarged_radius);
    sfCircleShape_setOrigin(hitbox,
        (sfVector2f){enlarged_radius, enlarged_radius});
    sfCircleShape_setPosition(hitbox,
        (sfVector2f){tower->position.x, tower->position.y});
    sfCircleShape_setOutlineColor(hitbox, sfRed);
    sfCircleShape_setOutlineThickness(hitbox, 2.0);
    sfCircleShape_setFillColor(hitbox, sfTransparent);
    if (must_display->display_towers_hitbox == 1)
        sfRenderWindow_drawCircleShape(window, hitbox, NULL);
    sfCircleShape_destroy(hitbox);
}

void display_tower(sfRenderWindow *window, tower_t *tower,
    hitbox_t *must_display)
{
    while (tower != NULL) {
        sfRenderWindow_drawSprite(window, tower->sprite, NULL);
        display_tower_hitbox(window, tower, must_display);
        tower = tower->next;
    }
}
