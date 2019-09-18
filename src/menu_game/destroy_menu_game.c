/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy_menu_game.c
*/

#include "basics.h"
#include "my_rpg.h"
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "menu.h"

void destroy_menu_game(menu_t *menu)
{
    destroy_sprite(&menu->menu_w);
    for (int i = 0; i < NBR_BUTTON; i += 1)
        destroy_text(&menu->buttons[i].text);
    free(menu->buttons);
    free(menu);
}