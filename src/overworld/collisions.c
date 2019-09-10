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

void check_can_go_ground(sfVector2f objective,
ground_t *ground, int *is_ground, int *is_blocked)
{
    if (ground->pos.x != objective.x || ground->pos.y != objective.y)
        return;
    if (ground->solid == 1)
        *is_blocked += 1;
    else if (ground->solid == 0)
        *is_ground += 1;
}

int check_can_go(character_t *character,
game_object_list_t *list, sfVector2f objective)
{
    int is_ground = 0;
    int is_blocked = 0;

    while (list != NULL && is_blocked == 0) {
        if (list->type == GROUND) {
            check_can_go_ground(objective,
            (ground_t *)(list->object), &is_ground, &is_blocked);
        }
        list = list->next;
    }
    if (is_ground > 0 && is_blocked == 0)
        return (1);
    return (0);
}
