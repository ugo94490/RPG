/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** interact
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"
#include "basics.h"

void wait_quest_shoes(game_t *game, npc_t *npc)
{
    if (!check_has_shoes(game->character->items)) {
        if (npc->diag2)
            display_text_overworld(game->window, npc->diag2, game);
    }
    else if (npc->diag1) {
        destroy_quest(&(game->character->quests), 1);
        display_text_overworld(game->window, npc->diag1, game);
    }
}

void basic_npc_interact(game_t *game, npc_t *npc)
{
    if (npc->aggro == 1)
        aggro(game, npc);
    if (npc->aggro == 0 && npc->diag1)
        display_text_overworld(game->window, npc->diag1, game);
}

void npc_interact(game_t *game, npc_t *npc)
{
    void (*npc_interact_ptr[])(game_t *, npc_t *) = {basic_npc_interact,
        get_quest_shoes, wait_quest_shoes};

    set_npc_direction_interact(game->character, npc);
    animate_npc(npc);
    draw_game(game->window, game);
    (*npc_interact_ptr[npc->interact])(game, npc);
}

void sub_interact(game_t *game, sfVector2f postry)
{
    evt_list_t *evts = game->evts;
    game_object_list_t *list = game->objects;

    while (evts) {
        if (evts->event.trigger == 3 && box_box_col(postry,
            standardColRect, evts->event.pos, standardColRect) == 1)
            activate_event(game, evts);
        evts = evts->next;
    }
    while (list) {
        if (list->type == NPC && box_box_col(((npc_t *)(list->object))->pos,
            standardColRect, postry, standardColRect) == 1)
            npc_interact(game, (npc_t *)(list->object));
        list = list->next;
    }
}

void interact(game_t *game)
{
    sfVector2f postry = {game->character->pos.x, game->character->pos.y};

    if (game->character->direction == 1)
        postry.y = game->character->pos.y + ground_height;
    if (game->character->direction == 3)
        postry.y = game->character->pos.y - ground_height;
    if (game->character->direction == 4)
        postry.x = game->character->pos.x - ground_width;
    if (game->character->direction == 2)
        postry.x = game->character->pos.x + ground_width;
    sub_interact(game, postry);
}
