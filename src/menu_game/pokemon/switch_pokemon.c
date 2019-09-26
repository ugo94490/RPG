/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** switch_pokemon.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

pkmn_list_t *switch_pokemon(pkmn_bag_t *pkmn_bag)
{
    pkmn_list_t *tmp = pkmn_bag->param->list_pkmn;

    for (int i = 1; i < pkmn_bag->n_slot; i += 1)
        pkmn_bag->param->list_pkmn = pkmn_bag->param->list_pkmn->next;
}