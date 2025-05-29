/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my
*/

#ifndef MY
    #define MY

    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <ctype.h>

typedef struct my_linkedlist_s {
    int data;
    struct my_linkedlist_s *next;
} my_linkedlist_t;

int is_prime_number(int nb);
int my_getnbr(char const *str);
int my_isalnum(int c);
int my_isalpha(int c);
int my_isdigit(char c);
int my_isnumber(char *str);
int linkedlist_len(my_linkedlist_t *list);
int my_printf(const char *format, ...);
int my_put_char(int c);
int my_put_expo(double i);
int my_put_expomaj(double i);
int my_put_float(double i);
int my_put_hexa(int ii);
int my_put_hexamaj(int ii);
int my_put_long(long nb);
int my_put_nbr_str(char *str);
int my_put_nbr(int nb);
int my_put_oct(int nb);
int my_put_ptr(char *str);
int my_put_unsigned(int i);
char *my_revstr(char *str);
int my_str_cmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, const char *to_find);
char **my_str_to_word_array(char const *str);
void free_word_array(char **word_array, int word_count);
int my_atoi(const char *str);

#endif /* MY */
