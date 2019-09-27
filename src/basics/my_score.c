/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_score.c
*/

#include <stdlib.h>

char *my_score(int nb)
{
    int size_str = 1;
    int power = 1;
    int i = 0;
    char *str = NULL;

    while ((nb / power) >= 10) {
        power *= 10;
        size_str = size_str + 1;
    }
    str = malloc(sizeof(char) * (size_str + 1));
    while (power >= 10) {
        str[i] = (nb / power) + '0';
        nb = nb - (nb / power) * power;
        power = power / 10;
        i = i + 1;
    }
    str[i] = nb % 10 + '0';
    str[i + 1] = '\0';
    return (str);
}