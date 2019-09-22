/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** animate_characters
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

void animate_npc_direction(npc_t *npc)
{
    if (npc->direction == 1) {
        npc->anim.baserect = 0;
        npc->anim.endrect = 0;
    }
    if (npc->direction == 2) {
        npc->anim.baserect = 4;
        npc->anim.endrect = 4;
    }
    if (npc->direction == 3) {
        npc->anim.baserect = 8;
        npc->anim.endrect = 8;
    }
    if (npc->direction == 4) {
        npc->anim.baserect = 12;
        npc->anim.endrect = 12;
    }
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

void animate_npc(npc_t *npc)
{
    animate_npc_direction(npc);
    if (npc->status == 1) {
        npc->anim.endrect += 3;
        npc->anim.time_anim = 150000;
    }
    sub_animate(&(npc->anim));
}
