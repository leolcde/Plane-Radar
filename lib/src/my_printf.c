/*
** EPITECH PROJECT, 2024
** printf
** File description:
** printf
*/

#include "../include/my.h"

const int (*ope[])(int) = {my_put_oct, my_put_nbr, my_put_char,
    my_put_hexa, my_put_hexamaj, my_put_nbr, my_put_unsigned};
const int (*ope2[])(double) = {my_put_float, my_put_expo, my_put_expomaj};

static char sorterdouble(const char *format, va_list args)
{
    char *str = "feE";
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == *format) {
            ope2[i](va_arg(args, double));
        }
        i++;
    }
}

static char sorter(const char *format, va_list args)
{
    char *str = "odcxXiu";
    int i = 0;
    int check = 0;

    if (*format == 's')
        my_put_ptr(va_arg(args, char *));
    if (*format == '%')
        my_put_char('%');
    while (str[i] != '\0') {
        if (str[i] == *format) {
            ope[i](va_arg(args, int));
            check++;
        }
        i++;
    }
    if (check == 0)
        sorterdouble(format, args);
}

int my_printf(const char *format, ...)
{
    va_list args;
    int index = 0;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
                format++;
                sorter(format, args);
                format++;
        }
        my_put_char(*format);
        format++;
    }
    va_end(args);
    return 0;
}
