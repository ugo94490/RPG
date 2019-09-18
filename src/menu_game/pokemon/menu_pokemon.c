/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_pokemon.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static void menu_pkmn_bag_loop(pkmn_bag_t *pkmn_bag)
{
    clock_sf time_loop = create_clock();

    while (pkmn_bag->state == OPEN) {
        sfClock_restart(time_loop.clock);
        sfRenderWindow_clear(pkmn_bag->window->window, sfBlack);
        display_pokemon_bag(pkmn_bag);
        sfRenderWindow_display(pkmn_bag->window->window);
        analyse_pokemon_bag(pkmn_bag);
    }
    sfClock_destroy(time_loop.clock);
}

void menu_pokemon(window_t *window)
{
    pkmn_bag_t *pkmn_bag = create_pkmn_bag(window);

    menu_pkmn_bag_loop(pkmn_bag);
    destroy_pokemon_bag(pkmn_bag);
}