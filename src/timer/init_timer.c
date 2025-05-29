/*
** EPITECH PROJECT, 2025
** radarsave
** File description:
** init_timer
*/

#include "../../includes/my.h"

sfClock *create_clock(void)
{
    return sfClock_create();
}

float get_elapsed_time(sfClock *clock)
{
    sfTime elapsedTime = sfClock_getElapsedTime(clock);

    return sfTime_asSeconds(elapsedTime);
}

void init_timer(timer_radat_t *timer)
{
    timer->font = sfFont_createFromFile("content/arial.ttf");
    if (timer->font == NULL) {
        return;
    }
    timer->text = sfText_create();
    sfText_setFont(timer->text, timer->font);
    sfText_setCharacterSize(timer->text, 50);
    sfText_setFillColor(timer->text, sfWhite);
    sfText_setOutlineThickness(timer->text, 2.0f);
    sfText_setOutlineColor(timer->text, sfBlack);
    timer->position.x = 1700;
    timer->position.y = 50;
    sfText_setPosition(timer->text, timer->position);
}

void reset_clock(sfClock *clock)
{
    sfClock_restart(clock);
}
