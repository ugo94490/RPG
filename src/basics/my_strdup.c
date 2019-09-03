/*
** EPITECH PROJECT, 2019
** CPool_Day08_2018
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *c = malloc(sizeof(char) * my_strlen(src) + 1);

    if (c == NULL)
        exit(84);
    for (int i = 0; src[i] != '\0'; i = i + 1) {
        c[i] = src[i];
    }
    c[my_strlen(src)] = '\0';
    return (c);
}
