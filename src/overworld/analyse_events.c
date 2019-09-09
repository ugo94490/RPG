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

void get_key_pressed(window_t *window, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->window);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        move_right(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        move_left(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move_down(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        move_up(window, game);
}

void analyse_event(window_t *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
    get_key_pressed(window, game);
}
