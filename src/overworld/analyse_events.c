/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_events
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"
#include "overworld_evt.h"
#include "my_rpg.h"
#include "overworld_sound.h"
#include "menu.h"

void display_text_overworld(window_t *window, char *text, game_t *game)
{
    sfVector2f temppos = {(game->character->pos.x+character_width/2)
        *window->scale.x, (game->character->pos.y+
        character_height/6)*window->scale.y};
    sfVector2f textpos = {temppos.x - 148 * window->scale.x,
        temppos.y + 187 * (window->scale.y)};

    display_text(text, textpos, window, 1);
}

void get_key_pressed(window_t *window, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        move_right(game);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        move_left(game);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move_down(game);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        move_up(game);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        interact(game);
    if (sfKeyboard_isKeyPressed(sfKeyTab))
        menu_game(game, window);
}

void analyse_event(window_t *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->window);
    if (sfRenderWindow_isOpen(window->window) && game->character->status == 0)
        get_key_pressed(window, game);
}
