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
    free(pkmn_bag->slot);
    free(pkmn_bag);
    pkmn_bag = NULL;
}