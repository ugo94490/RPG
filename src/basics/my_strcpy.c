/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** strcpy
*/

char *my_strcpy(char *new, char *base)
{
    int cpt = 0;

    for (; base[cpt] != '\0'; ++cpt)
        new[cpt] = base[cpt];
    new[cpt] = '\0';
    return new;
}
