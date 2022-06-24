/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_putchar, my_putstr, my_strlen
*/

#include "../include/hunter.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}

int get_random_nb(int a, int b)
{
    int random_nb = 0;

    random_nb = rand()%(b - a) + a;
    return (random_nb);
}
