/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_npc
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"

void set_pos_to_objective_npc(npc_t *npc)
{
    npc->pos = npc->objective;
    npc->status = 0;
}

void sub_move_npc(npc_t *npc, float speed, sfTime time)
{
    if (npc->direction == 1) {
        npc->pos.y += speed * time.microseconds/1000000;
        if (npc->pos.y >= npc->objective.y)
            set_pos_to_objective_npc(npc);
    }
    if (npc->direction == 2) {
        npc->pos.x += speed * time.microseconds/1000000;
        if (npc->pos.x >= npc->objective.x)
            set_pos_to_objective_npc(npc);
    }
    if (npc->direction == 3) {
        npc->pos.y -= speed * time.microseconds/1000000;
        if (npc->pos.y <= npc->objective.y)
            set_pos_to_objective_npc(npc);
    }
    if (npc->direction == 4) {
        npc->pos.x -= speed * time.microseconds/1000000;
        if (npc->pos.x <= npc->objective.x)
            set_pos_to_objective_npc(npc);
    }
}

void move_npc(npc_t *npc, sfTime time)
{
    float speed = 0;

    if (npc->status == 0)
        return;
    if (npc->status == 1)
        speed = 100.0;
    if (npc->status == 1 || npc->status == 2)
        sub_move_npc(npc, speed, time);
}
