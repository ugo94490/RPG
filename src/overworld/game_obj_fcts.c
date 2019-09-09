/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_obj_fcts
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "systems.h"
#include "graphics.h"
#include "basics.h"
#include "game_object.h"

void put_object_in_objects(game_object_list_t **list, void *object,
int type, int height)
{
    game_object_list_t *element = malloc(sizeof(game_object_list_t));
    if (element == NULL)
        return;

    element->object = object;
    element->type = type;
    element->height = height;
    element->next = *list;
    *list = element;
}
