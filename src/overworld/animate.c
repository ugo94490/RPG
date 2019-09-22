/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** animate
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void sub_animate(anim_t *anim)
{
    anim->clock.time = sfClock_getElapsedTime(anim->clock.clock);
    if (anim->clock.time.microseconds > anim->time_anim) {
        anim->actual_rect += 1;
        sfClock_restart(anim->clock.clock);
    }
    if (anim->actual_rect > anim->endrect || anim->actual_rect < anim->baserect)
        anim->actual_rect = anim->baserect;
}

void animate_objects(game_t *game)
{
    game_object_list_t *list = game->objects;

    while (list != NULL) {
        if (list->type == PLAYER)
            animate_player((character_t *)(list->object));
        if (list->type == GROUND)
            (((ground_t *)(list->object))->animfct)
            (game, (ground_t *)(list->object), &list->height);
        if (list->type == NPC)
            animate_npc((npc_t *)(list->object));
        list = list->next;
    }
}
