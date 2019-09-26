/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy game
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "systems.h"
#include "graphics.h"
#include "game_object.h"
#include "overworld.h"

void destroy_object_list(game_object_list_t *list)
{
    if (list && list->next)
        destroy_object_list(list->next);
    if (list)
        destroy_object(list);
}

void destroy_evt_list(evt_list_t *list)
{
    if (list && list->next)
        destroy_evt_list(list->next);
    if (list)
        free(list);
}

void destroy_game(game_t *game)
{
    for (int i = 0; i < 3; i++)
        destroy_sprite(&(game->sprites[i]));
    free(game->sprites);
    destroy_object_list(game->objects);
    destroy_evt_list(game->evts);
    sfView_destroy(game->view);
    sfMusic_destroy(game->music);
}
