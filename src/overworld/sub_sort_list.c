/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sub_sort_objects
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "basics.h"
#include "game_object.h"

float get_posy_obj(game_object_list_t *node)
{
    if (node->type == PLAYER)
        return (((character_t *)(node->object))->pos.y);
    if (node->type == GROUND)
        return (((ground_t *)(node->object))->pos.y);
    if (node->type == NPC)
        return (((npc_t *)(node->object))->pos.y);
}

void push_in_other_list(game_object_list_t **list, game_object_list_t **dest)
{
    game_object_list_t *save = (*list)->next;

    put_object_in_objects(dest, (*list)->object, (*list)->type, (*list)->height);
    free(*list);
    *list = save;
}

void reverse_first_two_elements(game_object_list_t **list)
{
    game_object_list_t save;

    save.object = (*list)->object;
    save.height = (*list)->height;
    save.type = (*list)->type;
    (*list)->object = (*list)->next->object;
    (*list)->type = (*list)->next->type;
    (*list)->height = (*list)->next->height;
    (*list)->next->object = save.object;
    (*list)->next->height = save.height;
    (*list)->next->type = save.type;
}
