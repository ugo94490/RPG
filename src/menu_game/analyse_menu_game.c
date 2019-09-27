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

static void manage_button(game_t *game, menu_t *menu)
{
    sfVector2f pos = {800, 800};

    if (menu->n_button == QUIT)
        sfRenderWindow_close(game->window->window);
    if (menu->n_button == RELEASE)
        menu->state = RELEASE;
    if (menu->n_button == POKEMON)
        menu->state = POKEMON;
    if (menu->n_button == SAVE) {
        save_game(game);
        display_text_overworld(game->window, "Game saved...", game);
    }
}

static void analyse_keyboard_menu_game(game_t *game, menu_t *menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && menu->n_button < 7) {
        menu->select.pos_select.y += 46;
        menu->n_button += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && menu->n_button > 0) {
        menu->select.pos_select.y -= 46;
        menu->n_button -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        manage_button(game, menu);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        menu->state = RELEASE;
}

void analyse_menu_game(game_t *game, menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(menu->window->window, &event))
        if (event.type == sfEvtKeyPressed)
            analyse_keyboard_menu_game(game, menu);
}