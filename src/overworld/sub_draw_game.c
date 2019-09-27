/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_draw_game
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

int check_if_draw(game_object_list_t *object, character_t *character, int level)
{
    sfVector2f pos;

    if (object->height != level)
        return (0);
    if (object->type == GROUND)
        pos = (((ground_t *)(object->object))->pos);
    if (object->type == NPC)
        pos = (((npc_t *)(object->object))->pos);
    if (object->type == PLAYER)
        return (1);
    if (pos.x > character->pos.x + 400 || pos.x < character->pos.x - 400 ||
    pos.y > character->pos.y + 300 || pos.y < character->pos.y - 300)
        return (0);
    return (1);
}
