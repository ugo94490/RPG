/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** restart funciton text
*/

#include "text.h"

char *set_to_base(char *str, char *save)
{
    free(str);
    free(save);
    save = NULL;
    return save;
}
