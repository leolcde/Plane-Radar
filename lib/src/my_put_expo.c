/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_expo
*/

#include "../include/my.h"

static int displayexpo(int ind, int checkneg)
{
    my_put_char('e');
    if (checkneg == 0 || checkneg > 0) {
        my_put_char('+');
    } else {
        my_put_char('-');
    }
    my_put_char('0');
    my_put_nbr(ind);
}

int my_put_expo(double i)
{
    int null = i;
    int ind = 0;
    int checkneg = 0;

    for (; null == 0; ind++) {
        i *= 10;
        null = i;
        checkneg = -1;
    }
    if (i <= 0) {
        i *= -1;
        checkneg = 1;
    }
    for (; i > 10; ind++)
        i /= 10;
    if (checkneg == 1)
        my_put_char('-');
    my_put_float(i);
    displayexpo(ind, checkneg);
}
