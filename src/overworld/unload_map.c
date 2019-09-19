/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** unload_map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "game_object.h"
#include "overworld.h"

void destroy_ground(ground_t *ground)
{
    if (ground == NULL)
        return;
    if (ground->anim.clock.clock != NULL)
        destroy_clock(&(ground->anim.clock));
    free(ground);
}

void destroy_object(game_object_list_t *object)
{
    if (object == NULL)
        return;
    if (object->type == GROUND)
        destroy_ground((ground_t *)(object->object));
    free(object);
}

void unload_map(game_object_list_t **objects)
{
    game_object_list_t *save = *objects;
    game_object_list_t *save2 = NULL;

    while (*objects != NULL && (*objects)->next != NULL) {
        if ((*objects)->next->type == GROUND) {
            save2 = (*objects)->next->next;
            destroy_object((*objects)->next);
            (*objects)->next = save2;
        }
        else
            *objects = (*objects)->next;
    }
    *objects = save;
    if (*objects != NULL && (*objects)->type == GROUND) {
        *objects = (*objects)->next;
        destroy_object(save);
    }
}
