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

void animate_player_direction(character_t *character)
{
    if (character->direction == 1) {
        character->anim.baserect = 0;
        character->anim.endrect = 0;
    }
    if (character->direction == 2) {
        character->anim.baserect = 4;
        character->anim.endrect = 4;
    }
    if (character->direction == 3) {
        character->anim.baserect = 8;
        character->anim.endrect = 8;
    }
    if (character->direction == 4) {
        character->anim.baserect = 12;
        character->anim.endrect = 12;
    }
}

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

void animate_player(character_t *character)
{
    animate_player_direction(character);
    if (character->status == 1) {
        character->anim.endrect += 3;
        character->anim.time_anim = 150000;
    }
    if (character->status == 2) {
        character->anim.baserect += 16;
        character->anim.endrect += 19;
        character->anim.time_anim = 100000;
    }
    sub_animate(&(character->anim));
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
        list = list->next;
    }
}
