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

void teleport(game_t *game, evt_t event)
{
    unload_map(&(game->objects));
    game->character->world = event.destmap;
    game->character->objective = event.dest;
    game->character->pos = event.dest;
    if (event.direction > 0)
        game->character->direction = event.direction;
    load_map(&(game->objects), event.destmap);
}

void activate_event(game_t *game, evt_t event)
{
    if (event.type == 1)
        teleport(game, event);
}

void check_evt_trigger(game_t *game)
{
    evt_list_t *save = game->evts;

    while (game->evts != NULL) {
        if (check_col_event(game->character, game->evts->event) == 1)
            activate_event(game, game->evts->event);
        game->evts = game->evts->next;
    }
    game->evts = save;
}

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
    if (sfKeyboard_isKeyPressed(sfKeyD))
        printf("%f, %f\n", game->character->pos.x, game->character->pos.y);
}

void analyse_event(window_t *window, game_t *game)
{
    sfEvent event;

    check_evt_trigger(game);
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
    get_key_pressed(window, game);
}
