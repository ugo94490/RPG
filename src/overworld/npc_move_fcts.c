/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** npc_move_fcts
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void move_npc_right(window_t *window, game_t *game, npc_t *npc)
{
    int newstatus = 1;
    sfVector2f newobjective = {npc->pos.x + ground_width,
    npc->pos.y};

    if (npc->status != 0)
        return;
    npc->direction = 2;
    if (check_can_go_np(npc, game->objects, newobjective) == 0)
        return;
    npc->objective = newobjective;
    update_npc_status(npc, newstatus, 2);
}

void move_npc_left(window_t *window, game_t *game, npc_t *npc)
{
    int newstatus = 1;
    sfVector2f newobjective = {npc->pos.x - ground_width,
    npc->pos.y};

    if (npc->status != 0)
        return;
    npc->direction = 4;
        if (check_can_go_np(npc, game->objects, newobjective) == 0)
        return;
    npc->objective = newobjective;
    update_npc_status(npc, newstatus, 4);
}

void move_npc_up(window_t *window, game_t *game, npc_t *npc)
{
    int newstatus = 1;
    sfVector2f newobjective = {npc->pos.x,
    npc->pos.y - ground_height};

    if (npc->status != 0)
        return;
    npc->direction = 3;
    if (check_can_go_np(npc, game->objects, newobjective) == 0)
        return;
    npc->objective = newobjective;
    update_npc_status(npc, newstatus, 3);
}

void move_npc_down(window_t *window, game_t *game, npc_t *npc)
{
    int newstatus = 1;
    sfVector2f newobjective = {npc->pos.x,
    npc->pos.y + ground_height};

    if (npc->status != 0)
        return;
    npc->direction = 1;
    if (check_can_go_np(npc, game->objects, newobjective) == 0)
        return;
    npc->objective = newobjective;
    update_npc_status(npc, newstatus, 1);
}
