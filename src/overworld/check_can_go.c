/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_can_go
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void check_can_go_ground(sfVector2f objective,
ground_t *ground, int *is_ground, int *is_blocked)
{
    if (!box_box_col(ground->pos, standardColRect, objective, standardColRect))
        return;
    if (ground->solid == 1)
        *is_blocked = 1;
    else if (ground->solid == 0)
        *is_ground = 1;
}

void check_can_go_npc(sfVector2f objective,
npc_t *npc, int *is_blocked)
{
    if (box_box_col(npc->pos, standardColRect, objective, standardColRect))
        *is_blocked = 1;
}

void check_can_go_character(sfVector2f objective,
character_t *character, int *is_blocked)
{
    if (box_box_col(character->pos, standardColRect, objective, standardColRect))
        *is_blocked = 1;
}

int check_can_go(character_t *character,
game_object_list_t *list, sfVector2f objective)
{
    int is_ground = 0;
    int is_blocked = 0;

    while (list != NULL && is_blocked == 0) {
        if (list->type == GROUND && list->height <= 3)
            check_can_go_ground(objective,
            (ground_t *)(list->object), &is_ground, &is_blocked);
        if (list->type == NPC &&
        ((npc_t *)(list->object))->world == character->world)
            check_can_go_npc(objective, (npc_t *)(list->object), &is_blocked);
        list = list->next;
    }
    if (is_ground == 1 && is_blocked == 0)
        return (1);
    return (0);
}

int check_can_go_np(npc_t *npc,
game_object_list_t *list, sfVector2f objective)
{
    int is_ground = 0;
    int is_blocked = 0;

    while (list != NULL && is_blocked == 0) {
        if (list->type == GROUND && list->height <= 3)
            check_can_go_ground(objective,
            (ground_t *)(list->object), &is_ground, &is_blocked);
        if (list->type == NPC)
            check_can_go_npc(objective, (npc_t *)(list->object), &is_blocked);
        if (list->type == PLAYER)
            check_can_go_character(objective, (character_t *)(list->object), &is_blocked);
        list = list->next;
    }
    if (is_ground == 1 && is_blocked == 0)
        return (1);
    return (0);
}
