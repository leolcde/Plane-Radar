/*
** EPITECH PROJECT, 2024
** Phoenix_Day2
** File description:
**  is_prime_number
*/

#include "../include/my.h"

int is_prime_number(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i <= nb / 2; i++) {
        if ((nb % i) == 0) {
            return 0;
        }
    }
    return 1;
}
