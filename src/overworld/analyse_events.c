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

void activate_event(game_t *game, evt_list_t *evt)
{
    if (evt->event.type == 1)
        teleport(game, evt->event);
    if (evt->perm == 0) {
        evt->event.type = 0;
        evt->perm = 1;
    }
    change_music(evt->event.music, &(game->music),
    &(game->character->music));
}

void check_evt_trigger(game_t *game, sfVector2f pos, int locmap)
{
    evt_list_t *save = game->evts;

    while (game->evts != NULL) {
        if (check_col_event(pos, locmap, game->evts->event) == 1)
            activate_event(game, game->evts);
        game->evts = game->evts->next;
    }
    game->evts = save;
}

npc_t *get_first_npc(game_object_list_t *list)
{
    while (list != NULL) {
        if (list->type == NPC)
            return ((npc_t *)(list->object));
        list = list->next;
    }
    return (NULL);
}

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
        move_right(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        move_left(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move_down(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        move_up(window, game);
    if (sfKeyboard_isKeyPressed(sfKeyP))
        printf("%f, %f\n", game->character->pos.x, game->character->pos.y);
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
    if (sfRenderWindow_isOpen(window->window) && game->character->status == 0) {
        check_evt_trigger(game, game->character->pos, game->character->world);
        get_key_pressed(window, game);
    }
}
