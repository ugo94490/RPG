/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fn_item.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static char *my_score(int nb)
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

void fn_item(pkmn_bag_t *pkmn_bag)
{
    char *buff = NULL;

    if (pkmn_bag->param->item == POTION &&
    pkmn_bag->param->list_pkmn->pokemon.health <
    pkmn_bag->param->list_pkmn->pokemon.max_health) {
        for (int i = 0; i < POTION &&
            pkmn_bag->param->list_pkmn->pokemon.health <
            pkmn_bag->param->list_pkmn->pokemon.max_health; i += 1)
            pkmn_bag->param->list_pkmn->pokemon.health += 1;
        buff = my_score(pkmn_bag->param->list_pkmn->pokemon.health);
        change_text(buff, &pkmn_bag->slot[pkmn_bag->n_slot - 1].pv);
    }
}