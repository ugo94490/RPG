/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** word_array_fcts
*/

#include <stdlib.h>

int get_nb_words(char **words)
{
    int i = 0;

    if (words == NULL)
        return (0);
    for (; words[i]; i++);
    return (i);
}
