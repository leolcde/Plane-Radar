/*
** EPITECH PROJECT, 2025
** radarsave
** File description:
** display_timer
*/

#include "../../includes/my.h"

void display_timer(sfRenderWindow *window, timer_radat_t *timer, float seconds)
{
    int minutes = (int)seconds / 60;
    int remaining_seconds = (int)seconds % 60;
    char time_str[10];

    time_str[0] = (minutes / 10) + '0';
    time_str[1] = (minutes % 10) + '0';
    time_str[2] = ':';
    time_str[3] = (remaining_seconds / 10) + '0';
    time_str[4] = (remaining_seconds % 10) + '0';
    time_str[5] = '\0';
    sfText_setString(timer->text, time_str);
    sfRenderWindow_drawText(window, timer->text, NULL);
}
