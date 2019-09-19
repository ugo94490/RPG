/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** collisions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

int box_box_col(sfVector2f box1pos, sfIntRect box1rect,
sfVector2f box2pos, sfIntRect box2rect)
{
    if ((box2pos.x >= (box1pos.x + box1rect.width))
    || ((box2pos.x + box2rect.width) <= box1pos.x)
    || (box2pos.y >= (box1pos.y + box1rect.height))
    || ((box2pos.y + box2rect.height) <= box1pos.y))
        return (0);
    else
        return (1);
}

int check_col_event(character_t *character, evt_t event)
{
    if (event.locmap != character->world)
        return (0);
    if (event.trigger == 1 && character->pos.x == event.pos.x &&
    character->pos.y == event.pos.y)
        return (1);
    if (event.trigger == 2 && box_box_col(character->pos,
    standardColRect, event.pos, standardColRect))
        return (1);
    return (0);
}

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

int check_can_go(character_t *character,
game_object_list_t *list, sfVector2f objective)
{
    int is_ground = 0;
    int is_blocked = 0;

    while (list != NULL && is_blocked == 0) {
        if (list->type == GROUND && list->height < 3) {
            check_can_go_ground(objective,
            (ground_t *)(list->object), &is_ground, &is_blocked);
        }
        list = list->next;
    }
    if (is_ground == 1 && is_blocked == 0)
        return (1);
    return (0);
}
