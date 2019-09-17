/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

static void analyse_keyboard_menu_game(menu_t *menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(menu->window->window);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && menu->n_button < 6) {
        menu->select.pos_select.y += 46;
        menu->n_button += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && menu->n_button > 0) {
        menu->select.pos_select.y -= 46;
        menu->n_button -= 1;
    }
}

void analyse_menu_game(menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(menu->window->window, &event)) {
        if (event.type == sfEvtKeyPressed)
           analyse_keyboard_menu_game(menu);
    }
}