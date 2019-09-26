/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static void menu_game_loop(game_t *game, menu_t *menu)
{
    clock_sf time_loop = create_clock();
    param_pkmn_menu_t param;

    param.item = NO;
    param.action = ORDER;
    while (menu->state != QUIT) {
        analyse_menu_game(game, menu);
        sfClock_restart(time_loop.clock);
        if (menu->state == NONE)
            display_menu_game(game, menu);
        if (menu->state == POKEMON) {
            menu_pokemon(menu->window, &param);
            menu->state = NONE;
        }
        sfRenderWindow_display(menu->window->window);
    }
    sfClock_destroy(time_loop.clock);
}

void menu_game(game_t *game, window_t *window)
{
    menu_t *menu = create_menu_game(window);

    if (!menu)
        return ;
    menu_game_loop(game, menu);
    destroy_menu_game(menu);
}
