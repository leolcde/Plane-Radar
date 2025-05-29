/*
** EPITECH PROJECT, 2025
** my_radarfinal
** File description:
** background
*/

#include "../../includes/my.h"

void background(sfRenderWindow *window, background_t *bg)
{
    bg->texture = sfTexture_createFromFile(
        "content/background.jpg", NULL);
    bg->sprite = sfSprite_create();
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
}

void dislay_background(sfRenderWindow *window, background_t *bg)
{
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
}
