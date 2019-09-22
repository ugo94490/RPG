/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_destroy_game
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"
#include "pkmn.h"

void free_pkmn_list(pkmn_list_t *list)
{
    if (list && list->next)
        free_pkmn_list(list);
    if (list)
        free(list);
}

void destroy_ground(ground_t *ground)
{
    if (ground == NULL)
        return;
    if (ground->anim.clock.clock != NULL)
        destroy_clock(&(ground->anim.clock));
    free(ground);
}

void destroy_character(character_t *character)
{
    if (character == NULL)
        return;
    free_pkmn_list(character->pkmns);
    if (character->anim.clock.clock != NULL)
        destroy_clock(&(character->anim.clock));
    free(character);
}

void destroy_npc(npc_t *npc)
{
    if (npc == NULL)
        return;
    if (npc->diag1)
        free(npc->diag1);
    if (npc->diag2)
        free(npc->diag2);
    free_pkmn_list(npc->pkmns);
    if (npc->anim.clock.clock != NULL)
        destroy_clock(&(npc->anim.clock));
    free(npc);
}

void destroy_object(game_object_list_t *object)
{
    if (object == NULL)
        return;
    if (object->type == GROUND)
        destroy_ground((ground_t *)(object->object));
    if (object->type == PLAYER)
        destroy_character((character_t *)(object->object));
    if (object->type == NPC)
        destroy_npc((npc_t *)(object->object));
    free(object);
}
