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

static void menu_game_loop(menu_t *menu)
{
    clock_sf time_loop = create_clock();

    while (sfRenderWindow_isOpen(menu->window->window)) {
        analyse_menu_game(menu);
        sfClock_restart(time_loop.clock);
        sfRenderWindow_clear(menu->window->window, sfBlack);
        if (menu->state == NONE)
            display_menu_game(menu);
        sfRenderWindow_display(menu->window->window);
    }
    sfClock_destroy(time_loop.clock);
}

void menu_game(window_t *window)
{
    menu_t *menu = create_menu_game(window);

    if (!menu)
        return ;
    menu_game_loop(menu);
    destroy_menu_game(menu);
}