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

static void heal(pkmn_bag_t *pkmn_bag, int stuff)
{
    pkmn_list_t *tmp = NULL;
    char *buff = NULL;

    tmp = pkmn_bag->param->list_pkmn;
    for (int i = 1; i < pkmn_bag->n_slot; i += 1)
        pkmn_bag->param->list_pkmn = pkmn_bag->param->list_pkmn->next;
    if (pkmn_bag->param->list_pkmn->pokemon.health ==
    pkmn_bag->param->list_pkmn->pokemon.max_health) {
        pkmn_bag->param->list_pkmn = tmp;
        return ;
    }
    for (int i = 0; i < stuff &&
        pkmn_bag->param->list_pkmn->pokemon.health <
        pkmn_bag->param->list_pkmn->pokemon.max_health; i += 1)
        pkmn_bag->param->list_pkmn->pokemon.health += 1;
    buff = my_score(pkmn_bag->param->list_pkmn->pokemon.health);
    change_text(buff, &pkmn_bag->slot[pkmn_bag->n_slot - 1].pv);
    pkmn_bag->param->list_pkmn = tmp;
}

static void revive(pkmn_bag_t *pkmn_bag)
{
    pkmn_list_t *tmp = NULL;
    char *buff = NULL;

    tmp = pkmn_bag->param->list_pkmn;
    for (int i = 1; i < pkmn_bag->n_slot; i += 1)
        pkmn_bag->param->list_pkmn = pkmn_bag->param->list_pkmn->next;
    if (pkmn_bag->param->list_pkmn->pokemon.health ==
    pkmn_bag->param->list_pkmn->pokemon.max_health) {
        pkmn_bag->param->list_pkmn = tmp;
        return ;
    }
    if (pkmn_bag->param->list_pkmn->pokemon.health == 0) {
        pkmn_bag->param->list_pkmn->pokemon.health = 50;
        buff = my_score(pkmn_bag->param->list_pkmn->pokemon.health);
        change_text(buff, &pkmn_bag->slot[pkmn_bag->n_slot - 1].pv);
    }
    pkmn_bag->param->list_pkmn = tmp;
}

void fn_item(pkmn_bag_t *pkmn_bag)
{
    if (pkmn_bag->param->item == POTION || pkmn_bag->param->item == S_POTION
        || pkmn_bag->param->item == H_POTION)
        heal(pkmn_bag, pkmn_bag->param->item);
    if (pkmn_bag->param->item == REVIVE)
        revive(pkmn_bag);
}