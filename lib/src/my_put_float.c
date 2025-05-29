/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_put_float
*/

#include "../include/my.h"

int printnull(double i)
{
    int index = 0;
    long nb = i * 1000000;
    long temp = nb;

    for (; temp < 100000; index++)
        temp *= 10;
    for (int p = index; p != 0; p--)
        temp /= 10;
    my_put_nbr(0);
    my_put_char('.');
    for (; index != 0; index--)
        my_put_nbr(0);
    my_put_nbr(nb);
}

int printpos(double i)
{
    int index = 0;
    long temp2 = i;
    long temp = i * 1000000;
    long temp3 = temp % (temp2 * 1000000);

    for (; temp3 < 100000; index++)
        temp3 *= 10;
    for (int p = index; p != 0; p--)
        temp3 /= 10;
    my_put_nbr(i);
    my_put_char('.');
    for (; index != 0; index--)
        my_put_nbr(0);
    my_put_nbr(temp3);
}

int my_put_float(double i)
{
    double neg = i * -1;
    int nb = i;

    if (nb > 0) {
        printpos(i);
    } else if (nb == 0) {
        printnull(i);
    } else {
        my_put_char('-');
        printpos(neg);
    }
    return 0;
}
