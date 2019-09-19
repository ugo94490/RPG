/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy_pokemon_bag.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

void destroy_pokemon_bag(pkmn_bag_t *pkmn_bag)
{
    destroy_sprite(&pkmn_bag->img);
    for (int i = 0; i < pkmn_bag->n_pkmn; i += 1) {
        destroy_text(&pkmn_bag->slot[i].pv);
        destroy_text(&pkmn_bag->slot[i].m_pv);
    }
    free(pkmn_bag->slot);
    free(pkmn_bag);
    pkmn_bag = NULL;
}